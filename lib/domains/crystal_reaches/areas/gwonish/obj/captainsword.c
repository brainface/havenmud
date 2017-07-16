#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

int critHits = 0;

int DoWield();
int CheckBlade(string skill);


static void create() 
{
  item::create();
  this_object()->AddSave( ({"critHits"}) );
  SetKeyName("greatsword");  
  /*  Edited by Duuk to make KeyName("sword") less common.
   *  Sorry Bal
 */
  SetId( ({ "sword","greatsword" }) );
  SetShort("a two-handed greatsword");
  SetLong("The double-edged greatsword is enormous");
  SetMaterial( ({"metal",}) );
  SetRepairSkills( ([
                     "metal working" : 12,
                     "weapon smithing" : 22
                 ]) );
  SetRepairDifficulty(25);
  SetMass(400); 
  SetValue(750);
  SetDamagePoints(5500);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetClass(20);
  SetVendorType(VT_WEAPON);
  SetHands(2);
  SetWield( (: DoWield :) );
}

int DoWield()
{
  if(this_player()->GetClass() == "fighter" || 
     this_player()->GetClass() == "cavalier" || 
     this_player()->GetClass() == "monk" ||
     this_player()->GetClass() == "sorcerer" ||
     this_player()->GetClass() == "paladin" ||
     this_player()->GetClass() == "ranger" )
  {
  this_player()->SetMorality(this_player()->GetMorality() - 10);
  this_player()->AddSkillBonus("slash combat", (: CheckBlade :) );
  message("system","%^RED%^Confidence surges through you when you "
                   "grasp the giant blade.%^RESET%^",this_player());
  message("system","%^RED%^" + this_player()->GetName() + " takes a "
                   "stance of power and wields a giant sword.%^RESET%^",
          environment(this_player()),this_player());
  this_player()->eventForce("cackle evilly");
  this_player()->AddTitle("the bearer of Ch'dichick's Blade");
  return 1;
  }
  else
  {
  message("system","The sword is just too difficult for one of your class to "
                   "wield.",this_player());
  return 0;
  }
}

int CheckBlade(string skill)
{
  if(!GetWorn())
  {
    previous_object()->RemoveSkillBonus("slash combat", this_object());
    return 0;
  }
  else 
  {
  return 5;
  }
}


int eventStrike(object target)
{
  object *combatants;
  
  combatants = (({ previous_object(),target}));
  
  if(random(5)) return item::eventStrike(target);
  
  message("system","%^RED%^The greatsword thrumms in your hand as it "
                   "impacts your foe.%^RESET%^",
          this_player());
  message("system","%^RED%^A low humm comes from " +
                   this_player()->GetName() +
                    "'s greatsword as it hits " +
                    target->GetKeyName() + ".%^RESET%^",
          environment(this_player()),
          combatants);
  message("system","%^RED%^" +  this_player()->GetName() + "'s greatsword "
                   "lands a crushing blow on you!%^RESET%^",
          target);
                   
  previous_object()->SetMorality(previous_object()->GetMorality() - 1);
  previous_object()->eventForce("cackle evilly");
  if(++critHits > 59)
  {
    message("system","%^GREEN%^A glow swirls around the greatsword, and "
                     "suddenly it is in near perfect shape again."
                     "%^RESET%^",
            this_player());
    message("system","%^GREEN%^A glow surrounds " + this_player()->GetName() +
                     "'s greatsword.%^RESET%^",
            environment(this_player()),this_player());
    this_object()->SetDamagePoints(5500);
    critHits = 0;
  }
  return item::eventStrike(target) + random(10) + 10;
}


mixed eventUnequip(object who)
{
  this_player()->RemoveTitle("the bearer of Ch'dichick's Blade");
  return item::eventUnequip(who);
}
