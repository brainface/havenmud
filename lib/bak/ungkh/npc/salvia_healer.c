/* EnjilCode */


#include <lib.h>

inherit LIB_HEALER;

int HealHealth();
int HealMagic();
void CheckHeal();
int DoHeal(object who, string args);

static void create() {
  healer::create();

  SetKeyName("Salvia");
  SetId( ({
    "salvia","healer","lizardman"
    }) );
  SetShort("salvia, the healer");
  SetLong("Tall and healthy, this lizardman prides herself on her "
          "health.  Her occupation is un-heard of in her race, making "
          "her one of a kind.  A aura of comfort that would sooth "
          "even the most savage mind surrounds her.");

  SetLevel(56);
  SetReligion("Kuthar","Kuthar");
  SetTown("Ungkh");
  SetRace("lizardman");
  SetMorality(250);
  SetClass("cleric");
  SetSkill("healing",65);
  SetSkill("enchantment",65);
  SetSpellBook( ([
    "mend" : 100,
    "paralysis" : 100,
    ]) );

  SetCombatAction(7, ({
    "!cast paralysis",
    "!cast mend on slavia",
    }) );
  SetAction(15, (: CheckHeal :) );
  SetLocalCurrency("skins");
  SetFees( ([
    "resurrect" : 15,
    "stamina" : 1,
    "health" : 3,
    "restore" : 6,
   ]) );
  SetGender("female");
  SetCurrency("skins",250 + random(175));

}

void CheckHeal() {
  if(GetHealthPoints() < GetMaxHealthPoints()) {
    eventForce("!cast mend");
  }
}

int DoHeal(object who, string args) {
  if(!args) {
    eventForce("speak Would you like me to heal your health"
              " or your magic?");
    return 1;
  }
  switch (args) {
    case "health" :
      HealHealth();
      break;
    case "magic" :
      HealMagic();
      break;
    default :
    eventForce("speak Would you like me to heal your health"
             " or your magic?");
      break;
    }
}

int HealHealth() {
  int hcure, skins, hmax, hheal;

  hmax = (int)this_player()->GetMaxHealthPoints();
  hcure = (int)this_player()->GetHealthPoints();
  hheal = hmax - hcure;
  skins = (hheal) = 99;
  if ( hmax == hcure ) {
    eventForce("speak You do not presently need my services!.");
    return 0;
  }
  if( (int)this_player()->GetCurrency("skins") < skins ) {
    eventForce("speak You cannot afford to be healed.");
    eventForce("speak The healing will cost you " + (int)skins + "skins");
    return 0;
  }
  this_player()->Addcurrency("skins",-skins);
  this_player()->eventHealDamage(hheal);
  eventForce("emote closes her eyes and concentrates");
  eventForce("speak You are healed.");
  return 0;
}

int HealMagic() {
  int mcure, skins, mmax, mheal;

  mmax = (int)this_player()->GetMaxMagicPoints();
  mcure = (int)this_player()->GetMagicPoints();
  mheal = mmax - mcure;
  skins = (mheal) * 450;
  if (mmax == mcure) {
    eventForce("speak Your magic doesn't need any healing");
    return 0;
  }
  if ( (int)this_player()->GetCurrency("skins") < skins ) {
    eventForce("speak You do not have enough money to be healed");
    eventForce("speak It will cost you "+ (int)skins + " skins.");
    return 0;
  }
  this_player()->AddCurrency("skins", -skins);
  this_player()->AddMagicPoints(mheal);
  eventForce("emote closes her eyes and concentrates.");
  eventForce("speak Your magic has been restored.");
  return 0;
}
