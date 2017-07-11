#include <lib.h>
#include "../path.h"

inherit LIB_NPC;

void SetSkinVars(string skin_type,int durability,int skin_value,int skin_mass);


static void create()
{
  npc::create();

  switch(random(3))
  {
  case 0:
      SetKeyName("crocodile");
      SetId( ({"crocodile", "croc"}) );
      SetAdjectives( ({ "small" }) );
      SetShort("a small crocodile");
      SetLong("Bumps cover the skin of this five foot long lizard.");
      SetRace("crocodile",1);
      SetClass("animal");
      SetLevel(3);
      
      AddLimb("torso",0,1);
      AddLimb("head","torso",1);
      AddLimb("front right leg","torso",3);
      AddLimb("front left leg","torso",3);
      AddLimb("back right leg","torso",3);
      AddLimb("back left leg","torso",3);
      AddLimb("tail","torso",4);

      
      if(random(3))
        SetGender("male");
      else
        SetGender("female");

      SetSkinVars("skin",180,20,35);

      SetAction(7,( { "The crocodile eyes you from a distance and smiles."} ));
      SetAction(7,( { "The crocodile swishes its tail."} ));
      break;

  case 1:
      SetKeyName("swamprat");
      SetId( ({"rat", "swamprat"}) );
      SetAdjectives( ({ "swamp" }) );
      SetShort("a swamprat");
      SetLong("Approximately the size of a large beaver, the swamprat "
              "is covered in filth.");
      
      SetRace("swamprat",1);
			SetClass("animal");
			SetLevel(2);
			
      AddLimb("torso",0,1);
      AddLimb("head","torso",1);
      AddLimb("front right leg","torso",3);
      AddLimb("front left leg","torso",3);
      AddLimb("back right leg","torso",3);
      AddLimb("back left leg","torso",3);
      AddLimb("tail","torso",4);

      if(random(3))
        SetGender("male");
      else
        SetGender("female");

      SetSkinVars("pelt",250,2,15);


      SetAction(7,( { "The swamprat noses around debris piles."} ));
      SetAction(7,( { "The swamprat approaches you with a gleam in "
                      "it's eyes.  It seems to be saying, 'Love me?'"} ));
      break;

  case 2:
      SetKeyName("anaconda");
      SetId( ({"snake", "anaconda",}) );
      SetAdjectives( ({ "baby" }) );
      SetShort("a baby anaconda");
      SetLong("Muscles ripple along the baby anaconda's coils.");
      
      SetRace("snake",1);
			SetClass("animal");
			SetLevel(2);
			
			
      AddLimb("torso",0,1);
      AddLimb("head","torso",1);
      AddLimb("tail","torso",4);

      if(random(3))
        SetGender("male");
      else
        SetGender("female");

      SetSkinVars("skin",80,25,15);


      SetAction(7,( { "The anaconda situates itself on an overhanging "
                      "limb."} ));
      SetAction(7,( { "The anaconda tests the air with its tongue."} ));
      break;

  }

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


