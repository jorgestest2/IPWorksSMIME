/*
 * IPWorks S/MIME 2022 C++ Edition - Demo Application
 *
 * Copyright (c) 2023 /n software inc. - All rights reserved. - www.nsoftware.com
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "../../include/ipworkssmime.h"
#define LINE_LEN 100

class MyCertMgr : public CertMgr
{
	//overwrite events here if needed
public:
	virtual int FireCertList(CertMgrCertListEventParams *e)
	{
		printf("%s\n", e->CertSubject);
		return 0;
	}
};

int main(int argc, char **argv)
{
	char * certStore = "./test.pfx";
	int certStoreSize;
	MyCertMgr certmgr;
	
	certmgr.SetCertStoreType(2); //CST_PFXFILE
	certmgr.SetCertStore(certStore, strlen(certStore));
	certmgr.SetCertStorePassword("test");
	certmgr.GetCertStore(certStore, certStoreSize);
	printf("Listing all certificates in store %s:\n\n", certStore);

	certmgr.ListStoreCertificates();
	if (certmgr.GetLastErrorCode())
	{
		printf("%d (%s)", certmgr.GetLastErrorCode(), certmgr.GetLastError());
	}
	printf("\npress <return> to continue...\n");
	getchar();
}


