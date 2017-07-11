/*  Object for livings guarding an exit
 * Duuktsaryth@Haven
 * 10-14-97
 */
#include <lib.h>
inherit LIB_ITEM;

void TestMe();
string SetBlocking(string dir);
string GetBlocking();
int eventAttemptPass(object who);
object SetOwner(object who);
object GetOwner();
int go(string dir);
int enter(string dir);
private object owner;
private string block;

static void create() {
  item::create();
  SetKeyName("guard object");
  SetInvis(1);
  SetShort("a guard object");
  SetLong("This is a guard object.");
  SetPreventGet("You cannot take that!");
  SetPreventDrop("You cannot drop that!");
  SetPreventPut("You cannot put that there!");
  call_out( (: TestMe :), 30);
  }

void init() {
  item::init();
  add_action("go","go");
  add_action("enter","enter");
  }

int go(string dir) {
  if ( (dir == GetBlocking()) || (dir == "into " + GetBlocking())) {
  return eventAttemptPass(this_player());
   }
  else return 0;
  }

int enter(string dir) {
  if (dir == GetBlocking()) {
  return (eventAttemptPass(this_player()));
    }
  else return 0;
  }

string SetBlocking(string dir) {
  return (block = dir);
  }

string GetBlocking() {
  return (block);
  }

object SetOwner(object who) {
  return (owner = who);
  }

object GetOwner() {
  return (owner);
  }

int eventAttemptPass(object who) {
  if (!GetOwner()) {
       return 0;
     }
  if (creatorp(who)) return 0;
  if (newbiep(GetOwner()) && userp(who)) return 0;
  if (GetOwner()->GetParalyzed()) return 0;
  if (!present(GetOwner()->GetKeyName(), environment())) {
     return 0;
    }
  if (this_player() == GetOwner()) return 0;
  who->AddStaminaPoints(-random(GetOwner()->GetStatLevel("strength")));
  GetOwner()->AddStaminaPoints(-random(who->GetStatLevel("strength")));
  if ((who->GetStatLevel("strength") + random(50) + (who->GetInvis() *20)) > 
       (GetOwner()->GetStatLevel("strength") + random(50)) ) {
    if (!(who->GetInvis()))
    send_messages("push",
        "$agent_name $agent_verb past $target_name.",
         who, GetOwner(), environment());
    return 0;
    }
  else {
    send_messages("are",
       "$agent_name $agent_verb blocked by $target_name.",
         who, GetOwner(), environment());
      return 1;
    }
  return 0;
  }

void TestMe() {
  if (!environment() || !(this_object())) { return 0; }
  if (!GetOwner()) { eventDestruct(); return 0; }
  if (!present(GetOwner()->GetKeyName(), environment()))
  {
    GetOwner()->eventPrint("Your vigilance in guarding fades.");
    eventDestruct(); 
  }
  call_out( (: TestMe :), 30);
  }

int Destruct() {
  if (GetOwner())
  GetOwner()->SetProperty("guarding", 0);
  ::Destruct();
  }
