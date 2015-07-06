#include <stdio.h>
#include <string.h>

int main(void) 
{
   FILE * lfp, * efp;
   int i, len, n;
   char line[80];
   char counter[80];

   lfp = fopen("events.labels", "r");
   efp = fopen("events.enum", "r");

   while (EOF != fscanf(efp, "%s", counter)) {
      fgets(line, sizeof(line), lfp);
      len = strlen(line);
      line[len-1] = '\0';
      printf("   strcpy(label[%s], \"%s\");\n", counter, line);
   }

   fclose(lfp);
   fclose(efp);
   
   return 0;
}
