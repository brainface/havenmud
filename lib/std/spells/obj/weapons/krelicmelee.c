#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

int SetCountDown(int timeLimit);
int GetCountDown();
string GetMaster();
void DoFade();
mixed DropTest(object who);
int countDown;
string SetMaster(string master);

string Master = "";

static void create() {
  item::create();
  SetKeyName("mithril knuckles");
  SetMaterial( ({ "mithril" }) );
  SetShort("a shimmering pair of mithril knuckles");
  SetId( ({ "knuckles" }) );
  SetAdjectives( ({ "shimmering", "mithril", "pair", "pair of" }) );
  SetClass(40);
  SetMass(25);
  SetValue(0);
  SetVendorType(VT_WEAPON);
  SetWeaponType("melee");
  SetDamageType(BLUNT|MAGIC|SHOCK);
  SetLong(
    "This small weapon is ment to be used over the hand. The knuckles are made "
    "completely out of mithril though magic seems to seep from the metal."
    );
  SetDamagePoints(20000);
  SetDestroyOnSell(1);
  SetPreventSteal(1);
  SetPreventDrop( (: DropTest :) );
  set_heart_beat(1);
}


int eventStrike(object target) {
  int amt;
  amt = random(20);
  if (!(random(5))) {
  switch (amt) {
    case 0..10:
      message("environment",
    "%^BOLD%^%^WHITE%^The knuckles seems to fade from existence for a momment.%^RESET%^",
        environment(target));
        amt += 20;
     break;
    case 11..15:
      message("environment",
      "%^BOLD%^%^BLUE%^The knuckles glows with light.%^RESET%^",
         environment(target));
        amt += 35;
      break;
    case 16..20:
      message("environment",
        "%^RED%^BOLD%^Electricity shoots out from the knuckles.%^RESET%^",
        environment(target));
        amt += 40;
      break;
    }
  return item::eventStrike(target) + amt;
  }
  return item::eventStrike(target);
 }

mixed DropTest(object who) {
      send_messages( ({ "exact" }),
         "The knuckles flickers out from existence.",
         this_object(), 0, who
       );
    call_out( (: eventDestruct :), 0 );
  return 0;
}

string SetMaster(string master){
        return (Master = master);
}

int SetCountDown(int timeLimit){
        return (countDown = timeLimit);
}

int GetCountDown(){
        return countDown;
}

string GetMaster(){
        return Master;
}

void heart_beat(){
    object room;
    object who;
    who = environment(this_object());

    if (!who) {
     eventDestruct();
     return;
    }  
    room = environment(who);
    if (!room) {
     eventDestruct();
     return;
    } 
    if (!living(who)){
     eventDestruct();
     return;
    }
        countDown--;
        if(!countDown) { DoFade(); }
        if(countDown < 0) { this_object()->eventDestruct(); }
}

void DoFade(){
        object caster;
        caster = environment(this_object());
        
        environment(this_object())->eventPrint("%^BOLD%^%^RED%^The knuckles "
        "shimmers from this reality.%^RESET%^", caster);
        eventDestruct();
}