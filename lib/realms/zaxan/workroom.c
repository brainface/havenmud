//
// Zaxan's Workroom
// Created by Zaxan@Haven
//

// Speeds up execution
#pragma save_binary

// Includes
#include <lib.h>
#include <rooms.h>
#include <objects.h>
#include <daemons.h>

// Definitions of SetLong()'s and the people invited in
#define OWNER "zaxan"
#define NORMAL "The Home of %^WHITE%^BOLD%^Zaxan%^RESET%^ "\
               "%^WHITE%^BOLD%^Zimtafarous%^RESET%^"
#define LOCKED "The Home of %^WHITE%^BOLD%^Zaxan%^RESET%^ "\
               "%^WHITE%^BOLD%^Zimtafarous%^RESET%^ "\
               "[%^GREEN%^BOLD%^access required%^RESET%^]"
#define SECURE "The Home of %^WHITE%^BOLD%^Zaxan%^RESET%^ "\
               "%^WHITE%^BOLD%^Zimtafarous%^RESET%^ "\
               "[%^RED%^BOLD%^secure%^RESET%^]"
#define ALLOWED ({ OWNER, "milquitoast", "amelia", "laoise", "zzaxan" })

// Inherits
inherit LIB_ROOM;

// Custom Functions
int PreExit();
int CheckOwner();

// Global Variables
int is_locked;
int lockout;
int noexits;
string *allowed_pers;

// Create function
static void create() {
   room::create();
   SetAmbientLight(50);
   SetClimate("indoors");
   SetShort(LOCKED);
   SetLong("This is where the mighty Zaxan does his idling..."
	   "I mean...work.");
   SetExits( ([ ]) );
   AddExit("north", "/domains/staff/staffroom", (: PreExit :));
   is_locked = 1;
   lockout = 0;
   noexits = 0;
   allowed_pers = ALLOWED;
}

void init()
{
   room::init();
// All of the cmds for the room
   add_action("lockstat", "lockstat");
   add_action("list", "list");
   add_action("commands", ({ "command", "commands" }));
   add_action("cmd_check", ({ "quit", "goto", "ed", "rm",
	                      "update", "dest", "duc" }));
// Cmds for owner only.
   if(this_player()->GetKeyName() == OWNER)
   {
      add_action("lockup", "lockup");
      add_action("unlock", "unlock");
      add_action("rmexits", "rmexits");
      add_action("addexits", "addexits");
      add_action("lockout", "lockout");
      add_action("invite", "invite");
      add_action("uninvite", "uninvite");
      add_action("eject", "eject");
   }
// End cmds
}

int CheckOwner()
{
   if(this_player() != find_living(OWNER))
   {
      message("system", "Piss off.", this_player());
      return 0;
   }

   return 1;
}

// Makes sure that someone is authorized to enter
int CanReceive(object who)
{
   if(!who) return 0;

   if(!userp(who) || adminp(who) || who->GetKeyName() == OWNER) return 1;

   if(lockout)
   {
      message("system", capitalize(OWNER)+" has locked the room "
	      "for privacy.", who);
      message("system", "%^BLUE%^BOLD%^"+who->GetName()+" just tried to "
              "penetrate the seal!%^RESET%^", this_object());
      return 0;
   }
   if(is_locked)
   {
      if(member_array(who->GetKeyName(), allowed_pers) != -1)
      {
	 message("system", "You have entered with an invitation.", who);
	 return 1;
      }
      else
      {
	 message("system", "The room is locked. Only those that "
	         "are invited may enter.", who);
	 message("system", "%^BLUE%^BOLD%^"+who->GetName()+" just tried to "
	         "penetrate the seal!%^RESET%^", this_object());
	 return 0;
      }
   }
   return 1;
}

// Makes sure things can leave...
int CanRelease(object who)
{
   if(!who) return 0;

   if(!userp(who) || adminp(who) || who->GetKeyName() == OWNER) return 1;

   if(noexits)
   {
      send_messages(0, "A large wall of %^GREEN%^green vines%^RESET%^ envelop "
	               "$target_name to prevent $target_objective from leaving!",
		       this_player(), who, this_object());
      return 0;
   }

   return 1;
}

int commands()
{
   message("system",
	   "command(s) : This info.\n"
	   "lockstat   : Status check of room's locks.\n"
	   "list       : List of owner and guests.\n"
	   "----------------------------------------------------------------\n"
	   "lockup     : Locks room, only invited people may enter.\n"
	   "lockout    : Only owner and admins may enter.\n"
	   "rmexits    : Removes all exits from the room.\n"
	   "addexits   : Re-adds all exits to theroom.\n"
	   "unlock     : Unlocks room. Anyone may enter.\n"
	   "invite     : Invites a specific person to enter the locked room.\n"
	   "uninvite   : Removes a person from the invite list.\n"
	   "eject      : Ejects a target to its last known environment.\n"
	   "----------------------------------------------------------------",
	   this_player());
   return 1;
}

// Removes all exits from the room
int rmexits()
{
   if(!CheckOwner()) return 1;

   noexits = 1;
   send_messages(({ "mumble", "wink" }),
	         "$agent_name $agent_verb an ancient phrase and $agent_verb.",
		 this_player(), 0, this_object());
   message("system", "Many %^GREEN%^green vines%^RESET%^ suddenly cover the walls.",
	 this_object());
   SetObviousExits("%^GREEN%^covered with vines%^RESET%^");
   return 1;
}

// Re-adds all exits to the room
int addexits()
{
   if(!CheckOwner()) return 1;

   noexits = 0;
   send_messages(({ "mumble", "wink" }),
	         "$agent_name $agent_verb an ancient phrase and $agent_verb.",
		 this_player(), 0, this_object());
   message("system", "The %^GREEN%^green vines%^RESET%^ retreat into the walls.",
	 this_object());
   SetObviousExits(0);
   return 1;
}

// Keeps people from doing stuff
int cmd_check()
{
   if(adminp(this_player())) return 0;

   if(noexits)
   {
      send_messages(0, "A large wall of %^GREEN%^green vines%^RESET%^ envelops "
	               "$target_name to prevent $target_objective from performing "
		       "a forbidden action!",
		       all_inventory(this_object()) & users() - ({ this_player() }),
		       this_player());
      return 1;
   }

   return 0;
}


// Locked to all but those allowed
int lockup()
{
   if(!CheckOwner()) return 1;

   is_locked = 1;
   lockout = 0;
   send_messages(({ "mumble", "wink" }),
	         "$agent_name $agent_verb an ancient phrase and $agent_verb.",
		 this_player(), 0, this_object());
   message("system", "Shield Set: %^GREEN%^BOLD%^access required%^RESET%^!",
	   this_object());
   SetShort(LOCKED);
   return 1;
}

// Total unlock. Anyone may enter
int unlock()
{
   if(!CheckOwner()) return 1;
   if(!is_locked && !lockout) return 1;
   
   is_locked = 0;
   lockout = 0;
   SetShort(NORMAL);
   send_messages(({ "mumble", "wink" }),
	         "$agent_name $agent_verb an ancient phrase and $agent_verb.",
		 this_player(), 0, this_object());
   message("system", "The room's seal has been broken.", this_player());
   return 1;
}

// adds to the invite list
int invite(string str)
{
   object ob;

   if(!str)
   {
      message("system", "Invite whom?", this_player());
      return 1;
   }
   str = lower_case(str);
   
   if(!CheckOwner()) return 1;

   if(!(ob = find_player(str)))
   {
      message("system", capitalize(str)+" is not logged on.",
	    this_player());
      return 1;
   }
   if(str == lower_case(OWNER))
   {
      message("system", "You can't invite yourself. You're the owner!",
	    this_player());
      return 1;
   }
   if(member_array(str, allowed_pers) != -1)
   {
      message("system", capitalize(str)+" is already invited.",
	    this_player());
      return 1;
   }
   allowed_pers += ({ str });
   send_messages("invite", "$agent_name $agent_verb $target_name into $agent_possessive "
	 "workroom.", this_player(), ob, this_object());
   return 1;
}
   
// Uninvites someone from the allowed list
int uninvite(string str)
{
   if(!str)
   {
      message("system", "Uninvite whom?", this_player());
      return 1;
   }
   str = lower_case(str);
   
   if(!CheckOwner()) return 1;

   if(str == lower_case(OWNER))
   {
      message("system", "You can't invite yourself. You're the owner!",
	    this_player());
      return 1;
   }
   if(member_array(str, allowed_pers) == -1)
   {
      message("system", capitalize(str)+" is already uninvited.",
	    this_player());
      return 1;
   }
   allowed_pers -= ({ str });
   message("system", "You uninvite "+capitalize(str)+".",
	 this_player());
   return 1;
}

// Info on lockup/lockout status
int lockstat()
{
   if(!lockout && !is_locked)
      message("system", "Shields down.", this_player());
   else if(lockout)
      message("system", "%^RED%^BOLD%^Maximum security!%^RESET%^", this_player());
   else
      message("system", "%^GREEN%^BOLD%^Access by invitation required.%^RESET%^",
	    this_player());

   return 1;
}

// All persons but OWNER and admins locked out
int lockout()
{
   if(!CheckOwner()) return 1;

   send_messages(({ "mumble", "wink" }),
	         "$agent_name $agent_verb an ancient phrase and $agent_verb.",
		 this_player(), 0, this_object());
   message("system", "Shield Set: %^RED%^BOLD%^maximum%^RESET%^!",
	 this_player());
   is_locked = 1;
   lockout = 1;
   SetShort(SECURE);
   return 1;
}

// Controls showing the status of invited people
string more_list(string name) {
   if(!find_player(name))
      return "not in the game right now";
   if(present(name, this_object()))
      return "right here";
   else
      return "at "+file_name(environment(find_player(name)));
   return "somewhere...not really sure...";
}

int list() {
   int i;

   message("system", "Permanent list:", this_player());
   message("system", "Host    "+capitalize(allowed_pers[0])+" is "+
      more_list(allowed_pers[0]), this_player());
   for(i=1;i<sizeof(allowed_pers);i++)
   {
      message("system", "Guest   "+capitalize(allowed_pers[i])+" is "+
	    more_list(allowed_pers[i]), this_player());
   }
   return 1;
}

// Eject sequence. Sends player to last environment
int eject(string str)
{
   object ob;

   if(!CheckOwner()) return 1;

   if(!(ob = present(str, this_object())))
   {
      message("system", "Failed to locate: "+str+".", this_player());
      return 1;
   }
   if((int)ob->GetLastEnvironment())
   {
      ob->eventMove(ob->GetLastEnvironment());
      if(present(ob, this_object()))
      {
	 message("system", "%^BOLD%^%^RED%^EJECT FAILED!!!%^RESET%^", this_player());
      }
      else
      {
	 send_messages("remove", "$agent_name $agent_verb $target_name from "
	       "$agent_possessive workroom!", this_player(), ob, this_object());
      }
      return 1;
   }
   else
   {
      ob->eventMove(ROOM_START);
      if(present(ob, this_object()))
      {
	 message("system", "%^BOLD%^%^RED%^EJECT FAILED!!!%^RESET%^", this_player());
      }
      else
      {
	 send_messages("remove", "$agent_name $agent_verb $target_name from "
	       "$agent_possessive workroom!", this_player(), ob, this_object());
      }
      return 1;
   }
   return 1;
}

// Keeps mortals out of Immortal-Only areas
int PreExit() {
   if(!creatorp(this_player())) {
      message("system", "Uh...no!", this_player());
      return 0;
   }
   return 1;
}
