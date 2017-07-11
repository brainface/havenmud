//
// The 'assume' object
// Object to maintain assumed NPC stuff
// Original author unknown
// Re-organized and modified by Zaxan@Haven
//

#include <lib.h>
#include <daemons.h>

inherit LIB_ITEM;

private int ActionChance = 0;
private int CombatActionChance = 0;
private string *Action = ({ });
private string *CombatAction = ({ });

static void create() {
   item::create();
   SetKeyName("assumed_npc_object");
   SetId( ({ "object" }) );
   SetInvis(1);
   SetPreventGet("");
   SetPreventDrop("");
   SetPreventPut("");
}

void init() {
   item::init();
   add_action("quit", "quit");
   add_action("remove", "remove");
   add_action("restore","restore");
   if(sizeof(environment()->GetAction())) {
      Action = environment()->GetAction();
      ActionChance = environment()->GetActionChance();
      environment()->SetAction(0, ({ }));
   }
   if(sizeof(environment()->GetCombatAction())) {
      CombatAction = environment()->GetCombatAction();
      CombatActionChance = environment()->GetCombatActionChance();
      environment()->SetCombatAction(0, ({ }));
   }
}

int restore(string useless) {
   object who = this_player();
   object body = environment()->GetProperty("assumed");

   if(!body) {
      message("system", "That body has been cleaned for lack of use. \n"
              "Please reconnect to get that body back. ", this_player());
      return 1;
   }
   environment()->SetAction(ActionChance, Action);
   environment()->SetCombatAction(CombatActionChance, CombatAction);
   foreach(string chan in environment()->GetChannels()) {
      environment()->RemoveChannel(chan);
   }
   exec(body, who);
   body->eventDescribeEnvironment();
   body->eventPrint("\n");
   CHAT_D->eventSendChannel("Assume Report", "reports",
           capitalize(this_player()->GetKeyName()) + " has ceased assuming "+
           environment()->GetShort()+" ("+file_name(environment())+").");
   environment()->RemoveProperty("assumed");
   body->RemoveProperty("assuming");
   this_object()->eventMove(body);
   if(immortalp(body)) eventDestruct();
   return 1;
}

int quit(string useless) {
   environment()->eventDestruct();
   return 1;
}

int remove(string useless) {
   environment()->eventMove("/domains/heaven/adm/void");
   return 1;
}

