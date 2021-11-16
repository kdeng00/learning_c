
#define ALLOCSIZE 9500

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;


char *alloc(int n);

void afree(char *p);
