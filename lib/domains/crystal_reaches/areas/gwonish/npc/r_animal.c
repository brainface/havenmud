#include <lib.h>
#include "../path.h"

inherit LIB_NPC;

void SetSkinVars(string skin_type,int durability,int skin_value,int skin_mass);


static void create() {
  npc::create();


      SetClass("animal");
  switch(random(4))  {
  case 0:
      SetKeyName("beaver");
      SetId( ({"beaver", "small beaver"}) );
      SetShort("a small beaver");
      SetLong("Mud crusts the nose of this small tree wrecker.");
      
      SetRace("rodent", "beaver");
      SetClass("animal");
      SetLevel(1);
      SetSkinVars("pelt",120,30,10);
      SetAction(7,( { "The beaver noses around some roots."} ));
      SetAction(7,( { "The beaver gnaws the base of a tree."} ));
      break;

  case 1:
      SetKeyName("rabbit");
      SetId( ({"rabbit", "little rabbit","bunny"}) );
      SetShort("a little rabbit");
      SetLong("The bunny twitches when you look too closely.");
      
      SetRace("rodent", "bunny");
      SetClass("animal");
      SetLevel(1);
      SetSkinVars("pelt",120,30,10);
      SetAction(7,( { "The rabbit quietly nibbles a clover."} ));
      SetAction(7,( { "The bunny freezes for a moment."} ));
      break;

  case 2:
      SetKeyName("garter snake");
      SetId( ({"snake", "garter snake"}) );
      SetShort("a garter snake");
      SetLong("The little garter snake slithers through the grass.");
      
      SetRace("snake");
      SetClass("animal");
      SetLevel(1);
      SetSkinVars("skin",50,10,5);
      SetAction(7,( { "The snake coils into a tight circle."} ));
      SetAction(7,( { "The snake hisses threateningly."} ));
      break;

  case 3:
      SetKeyName("wildcat");
      SetId( ({"wildcat", "cat"}) );
      SetShort("a wildcat");
      SetLong("The small wildcat stalks around the area.");
      
      SetRace("cat");
      SetClass("animal");
      SetLevel(2);
      SetSkinVars("pelt",90,20,10);
      SetAction(7,( { "The cat sharpens its claws."} ));
      SetAction(7,( { "The cat produces a disturbing howl."} ));
      break;
  }
  if(random(3))
        SetGender("male");
      else
        SetGender("female");
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


