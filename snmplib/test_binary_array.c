#include <net-snmp/net-snmp-config.h>

#if HAVE_IO_H
#include <io.h>
#endif
#include <stdio.h>
#if HAVE_STDLIB_H
#include <stdlib.h>
#endif
#if HAVE_MALLOC_H
#include <malloc.h>
#endif
#include <sys/types.h>
#if HAVE_STRING_H
#include <string.h>
#else
#include <strings.h>
#endif

#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/types.h>
#include <net-snmp/library/snmp_api.h>
#include <net-snmp/library/container.h>
#include <net-snmp/library/container_binary_array.h>
#include <net-snmp/library/tools.h>
#include <net-snmp/library/snmp_assert.h>

void
print_obj(netsnmp_index *i, void *v)
{
    printf("item %p = %ld\n", i, i->oids[0]);
}

#define TEST_SIZE 7
int
main(int argc, char**argv)
{
    oid o1 = 1;
    oid o2 = 2;
    oid o3 = 6;
    oid o4 = 8;
    oid o5 = 9;
    oid ox = 7;
    oid oy = 10;
    netsnmp_index i1,i2,i3,i4,i5,ix,iy, *ip;
    netsnmp_index *a[TEST_SIZE] = { &i1, &i2, &i3, &ix, &i4, &i5, &iy };
    netsnmp_container *c = netsnmp_container_get_binary_array();
    int i;

    c->compare = netsnmp_compare_netsnmp_index;
    
    i1.oids = &o1;
    i2.oids = &o2;
    i3.oids = &o3;
    i4.oids = &o4;
    i5.oids = &o5;
    ix.oids = &ox;
    iy.oids = &oy;
    i1.len = i2.len = i3.len = i4.len = i5.len = ix.len = iy.len = 1;

    printf("Creating container...\n");

    printf("Inserting data...\n");
    CONTAINER_INSERT(c,&i4);
    CONTAINER_INSERT(c,&i2);
    CONTAINER_INSERT(c,&i3);
    CONTAINER_INSERT(c,&i1);
    CONTAINER_INSERT(c,&i5);

    printf("For each...\n");
    CONTAINER_FOR_EACH(c, print_obj, NULL);
    printf("Done.\n");

    ip = CONTAINER_FIRST(c);
    printf("Find first = %p %ld\n",ip, ip->oids[0]);
    while( ip ) {
        ip = CONTAINER_NEXT(c,ip);
        if(ip)
            printf("Find next = %p %ld\n",ip, ip->oids[0]);
    }

    for( i=0; i < TEST_SIZE; ++i) {
        ip = CONTAINER_FIND(c,a[i]);
        printf("Find %ld = %p %ld\n", a[i]->oids[0], ip, ip ? ip->oids[0] : 0);
        ip = CONTAINER_NEXT(c,a[i]);
        printf("Next %ld = %p %ld\n", a[i]->oids[0], ip, ip ? ip->oids[0] : 0);
    }

    printf("Done.\n");

    return 0;
}
