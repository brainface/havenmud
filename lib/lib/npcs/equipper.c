// Amelia July 4 01
#include <lib.h>
inherit LIB_NPC;



mapping FreeEquipment;
int LevelLimit;
mapping SetFreeEquipment(mapping eq);
mapping GetFreeEquipment();
mapping AddFreeEquipment(mapping eqnew);
mapping RemoveFreeEquipment(mapping eqnew);
int Request(object who, string what);
int SetLevelLimit(int limit);
int GetLevelLimit();
int Give(object who, string cmd, string what);
int ListItems(object who);


static void create() {
   ::create();
   AddCommandResponse("give", (: Give :) );
   FreeEquipment = ([ ]);
   LevelLimit = 20;
}


int ListItems(object who) {
   if(who->GetLevel() > LevelLimit) {
      eventForce("speak You are too experienced to need my help!");
      return 1;
   }
   switch( sizeof(keys(FreeEquipment)) ) {
         case 0:
         eventForce("speak I am not currently providing items.");
         break;
         case 1:
         eventForce("speak Would you like a " + keys(FreeEquipment)[0] +
                    ", " + who->GetCapName() + "?");
         break;
         default:
         eventForce("speak What item did you want, " + who->GetCapName() +
                    "?  I can provide you with a " + (implode(  ( keys(FreeEquipment)
                    -({ keys(FreeEquipment)[0] }) ),
                    ", " ) ) + " and " + keys(FreeEquipment)[0] +
                    ".");
         break;
   }
   eventForce("speak Just request <item> from me!");
   return 1;
}

mapping SetFreeEquipment(mapping eq) {
   foreach( string item in (keys(FreeEquipment) - keys(eq)) ) {
      RemoveRequestResponse(item);
   }
   foreach(string item in keys(eq)) {
      AddRequestResponse(item, (: Request :));
   }
   return FreeEquipment = eq;
}

mapping AddFreeEquipment(mapping eqnew) {
   foreach(string item in keys(eqnew)) {
      AddRequestResponse(item, (: Request :));
   }
   return FreeEquipment += eqnew;
}

mapping RemoveFreeEquipment(array eqnew) {
   foreach( string item in (eqnew) ) {
      RemoveRequestResponse(item);
      map_delete(FreeEquipment, item);
   }
   return FreeEquipment;
}

mapping GetFreeEquipment() {
   return FreeEquipment;
}


int SetLevelLimit(int limit) {
   return LevelLimit = limit;
}

int GetLevelLimit() {
   return LevelLimit;
}


int Give(object who, string cmd, string what) {
   return Request(who, what);
}

int Request(object who, string what) {
   object newitem;
   if(!who) {
      eventForce("speak To whom should I give this item?");
      return 1;
   }
   if(!what || what == "") {
      ListItems(who);
      return 1;
   }
   if( (member_array(what, keys(FreeEquipment)) == -1) ) {
      ListItems(who);
      return 1;
   }
   if(who->GetLevel() > LevelLimit) {
      eventForce("speak You are much too experienced to need these items!");
      return 1;
   }
   if (who->GetReputation(GetTown()) < -100) {
    	eventForce("speak Why would I help someone as disliked as you?");
    	return 1;
    }
   newitem = new(FreeEquipment[what]);
   if (!newitem) {
     eventForce("speak Hmm.  I seem to be unable to give you one of those.");
     return 1;
    }
   newitem->eventMove(this_object());
   newitem->SetValue(0);
   newitem->SetPreventSell(1);
   eventForce("give first " + newitem->GetKeyName() + " to " + who->GetKeyName());
   eventForce("speak There you go, " + who->GetCapName() + ".  " +
              capitalize(newitem->GetShort()) + ".");
   return 1;
}
   
mixed eventAsk(object who, string args) {
   mixed tmp;
   if (tmp = npc::eventAsk(who, args) == 1) return 1;
   return ListItems(who);
}

mixed eventRequest(object who, string str) {
   mixed tmp;
   if (tmp = npc::eventRequest(who, str) == 1) return 1;
   return ListItems(who);
}

void eventGreet(object who) {
  ListItems(who);
}
