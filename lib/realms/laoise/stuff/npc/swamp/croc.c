#include <lib.h>
#include "../path.h"

inherit LIB_NPC;

void SetSkinVars(string skin_type,int durability,int skin_value,int skin_mass);


static void create()
{
  npc::create();
  SetKeyName("crocodile");
  SetId( ({"crocodile"}) );
  SetAdjectives( ({"juvenile","small"}) );
  SetShort("a juvenile crocodile");
  SetLong(
    "This crocodile is of a small size and appears "
    "not yet fully matured. His scales are the large "
    "plate shape common for his species, but his "
    "coloring is of a light tan color, which does not "
    "blend as well into the jungle as the dark tan of "
    "an adult crocodile. Because of this, he is more "
    "vulnerable to attacks and has only his large teeth "
    "to defend himself with."
  );
  SetLevel(3);
  SetRace("lizard","crocodile");
  SetClass("animal");
  SetGender("male");
  SetAction(7,({ 
    "The crocodile slowly opens his jaws and then quickly "
    "snaps them shut.",
    "The crocodile swishes his tail."
  }) );

  SetSkinVars("skin",180,20,35);
}

varargs int eventDie(object target)
{
  object ob;
  ob=new(GWONISH+"obj/generic_skin");

  ob->SetKeyName(GetKeyName()+" "+GetProperty("skin_type"));
  ob->SetDamagePoints(GetProperty("durability"));
  ob->SetShort("a "+GetKeyName()+" "+GetProperty("skin_type"));
  ob->SetLong("This is a "+
        GetProperty("skin_type")+" from a " +
        GetKeyName()+".");
  ob->SetID( ( {
    GetProperty("skin_type"),
    GetKeyName()+" "+GetProperty("skin_type")
      }) );
  ob->SetValue(GetProperty("skin_value"));
  ob->SetMass(GetProperty("skin_mass"));

  ob->eventMove(environment(this_object()));

  npc::eventDie(target);
}

void SetSkinVars(string skin_type,int durability,int skin_value,int skin_mass)
{
  SetProperty("skin_type",skin_type);
  SetProperty("durability",durability);
  SetProperty("skin_value",skin_value);
  SetProperty("skin_mass",skin_mass);
}



