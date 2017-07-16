// Probs Duuk ~2011
//
// Mahkefel making a note:
//   ingredients PROBABLY need to check by KeyName, otherwise things
//   with generic ids might qualify as ingredients??
#include <lib.h>
#include <daemons.h>
#include <std.h>
inherit LIB_DAEMON;

string Recipe;
string CraftedObject;
mapping Materials;
mapping Skills;
string *CraftingMessage;
int Unique;

static void create() {
        ::create();
        Recipe = "";
        CraftedObject = "";
        Materials = ([]);
        Skills = ([]);
        CraftingMessage = ({ "craft", "$agent_name $agent_verb $target_name." });
}

string SetRecipe(string x) { return Recipe = x; }
string GetRecipe()         { return Recipe;     }

string SetCraftedObject(string f) { return CraftedObject = f; }
string GetCraftedObject()         { return CraftedObject;     }

string* SetCraftingMessage(string* message) {return CraftingMessage = message;}
string* GetCraftingMessage() {return CraftingMessage;}

mapping SetMaterials(mapping m) { return Materials = m; }
mapping GetMaterials()          { return Materials;     }

mapping SetSkills(mapping m) { return Skills = m; }
mapping GetSkills()          { return Skills;     }

int SetUnique(int yesno) { return Unique = yesno; }
int GetUnique()          { return Unique;         }

int CanCraft(object who) {
  object *materials = ({ });
  object *my_inv = all_inventory(who);
  int count;
  if (who->CanCraft(Recipe) != 1) {
        who->eventPrint("You don't know how to craft that.");
        return 0;
  }
  foreach(string material, int num in Materials) {
    count = 0;
    foreach(object o in my_inv) {
      if (o->GetKeyName()==material) count++;
    }
    if (count < num) {
      who->eventPrint("You require " + num + " " + pluralize(material) + " to craft " + Recipe + ".");
      return 0;
    }
  }
  foreach(string skill in keys(Skills)) {
    if (who->GetSkillLevel(skill) < Skills[skill]) {
      who->eventPrint("You need a skill level of " + Skills[skill] + " in " + skill + " to craft that.");
      return 0;
    }
  }
  return 1;
}

int eventCraft(object who) {
  object *materials = ({ });
  object *my_inv = all_inventory(who);
  int count;
  object result;

  result = new(CraftedObject);
  if (!result) {
    who->eventPrint("The fabric of reality prevents you doing that right now.");
    error("**Bad CraftedObject in recipe " + identify(this_object()));
    return 1;
  }

  foreach(string material, int num in Materials) {
    count = 0;
    foreach(object o in all_inventory(who)) {
      if (o->GetKeyName()==material) { ({o})->eventDestruct(); count++; }
      if (count == num) break;
    }
  }
  result->eventMove(who);
  send_messages(CraftingMessage[0], CraftingMessage[1], who, result, environment(who));
  return 1;
}


