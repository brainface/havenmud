/* Adverb daemon
 * Duuk 01 13 03
 */
#include <lib.h>
#include <save.h>
inherit LIB_DAEMON;
void eventSave();
void eventRestore();

private string *Adverbs = ({ });

static void create() {
	::create();
        SetNoClean(1);
	eventRestore();
}
    
varargs int AddAdverbs(string array advs...) {
    if (!sizeof(Adverbs))
    {
	eventRestore();
    }
    Adverbs = distinct_array(Adverbs + advs);
    eventSave();
    return 1;
}

varargs int RemoveAdverb(string adverb) {
  if (!sizeof(Adverbs))
  {
     eventRestore();
  }
  Adverbs = distinct_array(Adverbs - ({ adverb }) );
  eventSave();
  return 1;
}

string array GetAdverbs() {
    if (!sizeof(Adverbs))
    {
	eventRestore();
    }
    return copy(Adverbs);
}

void eventSave() {
	unguarded( (: save_object, SAVE_ADVERBS :) );
}

void eventRestore()
{
    if (file_exists(SAVE_ADVERBS + __SAVE_EXTENSION__))
	unguarded( (: restore_object, SAVE_ADVERBS :) );
}
