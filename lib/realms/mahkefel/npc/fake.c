/*
 * an illusion template attempt 
*/
#include <lib.h>
inherit LIB_NPC;

string SetIllusionTarget(string target);
object GetIllusionTarget();
string IllusionTarget;

static void create(){
  npc::create();
  SetShort("a really fake dude");
  SetAdjectives(({"really","fake"}));
  SetLong("This is a really fake dude.");
  SetRace("kobold");
  SetGender("male");
  SetClass("rogue");
  SetKeyName("dude");
  SetId(({"dude", "illusion"}));
  SetAction(20,({"!emote continues to not exist."}));
  SetLevel(15);
}

object SetIllusionTarget(object target) {
  /*if (target->GetKeyName()) {
    IllusionTarget = target->GetKeyName(); 
  } else {
    return 0;
  }*/
  IllusionTarget = target;
}

object GetIllusionTarget() {
  object target;
  if (IllusionTarget) {
    debug("finding target :" + IllusionTarget);
    target = find_living(IllusionTarget);
    if (target) {
      return target;
    }
  }
  return 0;
}

string GetKeyName() {
  object target=GetIllusionTarget(); 
  if (target) {
    return target->GetKeyName(); 
  } else {
    return npc::GetKeyName(); 
  }
}

string array GetId() {
  object target=GetIllusionTarget(); 
  if (target) {
    return target->GetId() + npc::GetId(); 
  } else {
    return npc::GetId(); 
  }
}

string array GetAdjectives() {
  object target=GetIllusionTarget(); 
  if (target) {
    return target->GetAdjectives() + npc::GetAdjectives(); 
  } else {
    return npc::GetId(); 
  }  
}

string GetLong(string nom) {
  object target=GetIllusionTarget();
  if (target) {
    return target->GetLong(nom); 
  } else {
    return npc::GetLong(nom); 
  }
}

string GetShort(string nom) {
  object target=GetIllusionTarget();
  if (target) {
    return target->GetShort(); 
  } else {
    return npc::GetShort(); 
  }
}

/*
varargs mixed eventShow(object who, string component) {
  string desc;
  string owner_name;
  object owner;
  
  // illusions of arbitrary targets would need like,
  // a Set/GetIllusionTarget method, but for now, 
  // assuming the illusion is of the owner
  owner_name = this_object()->GetOwner();

  if (owner_name) {
    debug("finding owner :" + owner_name);
    owner = find_living(owner_name);
    if (!owner) {
      owner = this_object();
    }
  } else {
    owner = this_object();
  }
  
  debug ("doing override nonsense:");  
  if (component) {
    // oh god what are they doing i don't know bypass abort
    return ::eventShow(who, component);
  } else {
    desc = owner->GetLong(who);
    environment(who)->eventPrint(who->GetName() + " looks at " +
      GetShort() + ".", ({ who, this_object() }));    
  }

  who->eventPrint(desc);
  return 1;  
}

*/
