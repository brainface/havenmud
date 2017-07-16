/*    /secure/daemon/events.c
 *    from the Foundation II LPC Library
 *    an event monitoring daemon, for call outs across time
 *    created by Descartes of Borg 950501
 */

#include <lib.h>
#include <save.h>
#include <config.h>
#include <privs.h>
#include "events.h"

inherit LIB_DAEMON;

private int RebootInterval;
private mapping Events;
private static int InReboot = 0;

static void create() {
    daemon::create();
    SetNoClean(1);
    if( file_exists(SAVE_EVENTS __SAVE_EXTENSION__) )
      unguarded((: restore_object, SAVE_EVENTS :));
    if( !Events ) Events = ([]);
    eventSave();
    set_heart_beat(60);
    eventPollEvents();
}

void heart_beat() {
  eventPollEvents();
}

varargs static int eventSave(int ung) {
    if( ung ) {
	unguarded( (: save_object, SAVE_EVENTS :) );
	return 1;
    }
   else return unguarded( (: save_object, SAVE_EVENTS :) );
}

static void eventPollEvents() {
    int *events;
    int i, x;

    x = time();
    i = sizeof(events = keys(Events));
    while(i--) {
      if( events[i] <= x ) {
	      object ob;
	      function f;

	      if( !(ob = load_object(Events[events[i]]["creator"])) ) {
		      map_delete(Events, events[i]);
		      continue;
	        }
	      f = (: call_other, Events[events[i]]["object"],
		    Events[events[i]]["func"] :);
	      f = bind(f, ob);
        catch(evaluate(f, Events[events[i]]["args"]...));
        if( Events[events[i]]["regular"] > 3599 )
          Events[x + Events[events[i]]["regular"]] = Events[events[i]];
	      map_delete(Events, events[i]);
        }
    }
    eventSave();
}

void AddEvent(string c, string s, string f, mixed *a, int w, int r) {
    if( file_name(previous_object()) != SEFUN ) return;
    Events[time() + w] = ([ "object" : s, "function" : f, "args" : a,
			      "creator" : c,  "regular" : (r ? w : 0) ]);
    eventSave(1);
}

mapping GetEvents() { return copy(Events); }


