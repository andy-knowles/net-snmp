/* This file was generated by mib2c and is intended for use as a mib module
  for the ucd-snmp snmpd agent. */


#ifndef _MIBGROUP_MTEOBJECTSTABLE_H
#define _MIBGROUP_MTEOBJECTSTABLE_H


/* we may use header_complex from the header_complex module */


config_require(header_complex)


/* our storage structure(s) */
struct mteObjectsTable_data {

    char   *mteOwner;
    size_t  mteOwnerLen;
    char   *mteObjectsName;
    size_t  mteObjectsNameLen;
    unsigned long    mteObjectsIndex;
    oid     *mteObjectsID;
    size_t   mteObjectsIDLen;
    long    mteObjectsIDWildcard;
    long    mteObjectsEntryStatus;

};

/* enum definitions from the covered mib sections */


#define MTEOBJECTSIDWILDCARD_TRUE                1
#define MTEOBJECTSIDWILDCARD_FALSE               2

/* function prototypes */


void   init_mteObjectsTable(void);
FindVarMethod var_mteObjectsTable;
void parse_mteObjectsTable(const char *, char *);
SNMPCallback store_mteObjectsTable;
void mte_add_objects(struct variable_list *, struct mteTriggerTable_data *,
                     const char *, const char *, oid *, size_t);

WriteMethod write_mteObjectsID;
WriteMethod write_mteObjectsIDWildcard;
WriteMethod write_mteObjectsEntryStatus;

WriteMethod write_mteObjectsEntryStatus;



#endif /* _MIBGROUP_MTEOBJECTSTABLE_H */
