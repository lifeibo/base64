#include "base64.h"

#include <stdio.h>
#include <string.h>
#include <dejagnu.h>

int main()
{
	char* msg = "Hello there, base64 encoder!\n";
	size_t len = strlen(msg);
	size_t enclen = 0;
	size_t declen = 0;
	size_t i = 0;
	char* encmsg;
	char* decmsg;

	note("Message is: \"%s\"", msg);

	encmsg = base64_encode(&enclen, len, msg);
	if (encmsg == NULL) {
		fail("Encoded message was NULL");
	} else if (enclen <= len) {
		fail("Encoded message was too short");
	} else if (strnlen(encmsg, BUFSIZ) > BUFSIZ - 1) {
		fail("No terminating NULL in encoded message.");
	} else {
		pass("Encoded message seems plausible: \"%s\"", encmsg);
	}

	decmsg = base64_decode(&declen, enclen, encmsg);
	if (decmsg == NULL) {
		fail("Decoded message was NULL");
	} else if (declen >= enclen) {
		fail("Decoded message was too long for the encoded message");
	} else if (!strnlen(decmsg, BUFSIZ) > BUFSIZ - 1) {
		fail("No terminating NULL in decoded message.");
	} else if (strncmp(msg, decmsg, BUFSIZ) != 0) {
		fail("Decoded message does not match: \"%s\"", decmsg);
	} else {
		pass("Encoded message matches: \"%s\"", decmsg);
	}

	free(encmsg);
	free(decmsg);
	totals();
	return 0;
}


