/* combat/paralysis.c
 * controls paralysis and ending it
 * Duuktsaryth 3 Feb 1999
 */
#include <function.h>

varargs int      SetParalyzed(int, function);
int      GetParalyzed();
int      eventRemoveParalysis();
int      AddParalyzed(int);
/* virtual declarations */
void eventPrint(string);

private function endParalysis;
private int      Paralyzed;

static void create() {
  Paralyzed    = 0;
  endParalysis = 0;
}

varargs int SetParalyzed(int length, function end) {
  if (!length) { return eventRemoveParalysis(); }
  if (Paralyzed && (Paralyzed > length)) return Paralyzed;
  endParalysis = end;
  return (Paralyzed = length);
}

int AddParalyzed(int length) {
  if(Paralyzed + length <= 0) { 
  	eventRemoveParalysis(); 
  	return 0;
  	}
  return (Paralyzed += length);
}

int GetParalyzed() {
  if (Paralyzed < 0) { Paralyzed = 0; }
  return (Paralyzed);
}

int eventRemoveParalysis() {
  Paralyzed = 0;
  if (functionp(endParalysis)
      && (!functionp(endParalysis) & FP_OWNER_DESTED) )
    return evaluate(endParalysis);
  else {
    eventPrint("You can move again.");
    return 1;
  }
}

