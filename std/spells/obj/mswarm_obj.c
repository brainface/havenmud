// mswarm spell object
// Thoin
// 1-25-06
 

#include <lib.h>
#include <daemons.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_ITEM;

int SetCountDown(int timeLimit);
int GetCountDown();
int GetDamageAmount();
string GetMaster();
void DoFade();
void DoSwarm();
int countDown;
int Damage;
string SetMaster(string master);
int SetDamageAmount(int damage);

string Master = "";

static void create(){
        item::create();
        SetKeyName("meteor swarm");
        SetId( ({"mswarm_spell",}) );
        SetShort("a meteor");
        SetLong("mswarm spell object.");
        SetInvis(1);
        SetMass(1);
        SetValue(0);
        SetDamagePoints(5);
        SetPreventGet("You cannot drop that!");
        set_heart_beat(1);
}

void heart_beat(){
    object room;
    room = environment(this_object());

    if (!room) {
     eventDestruct();
     return;
    }  
 switch(random(100)) {  
  case 1..25 :
    return DoSwarm();
    break;
  default :
    environment(this_object())->eventPrint("%^BOLD%^%^RED%^The sky "
        "glows red and the clouds ripple slightly.%^RESET%^", room);
    break;
 }
        countDown--;
        if(!countDown) { DoFade(); }
        if(countDown < 0) { this_object()->eventDestruct(); }
}

string SetMaster(string master){
        return (Master = master);
}

int SetDamageAmount(int damage){
        return (Damage = damage);
}

int SetCountDown(int timeLimit){
        return (countDown = timeLimit);
}

int GetCountDown(){
        return countDown;
}

int GetDamageAmount(){
        return Damage;
}

string GetMaster(){
        return Master;
}

void DoFade(){
        object room;
        room = environment(this_object());
        
        environment(this_object())->eventPrint("%^BOLD%^%^BLUE%^The sky "
        "appears to clear.%^RESET%^", room);
        room->RemoveProperty("meteor_swarm");
        eventDestruct();
}

void DoSwarm(){
  object *critters;
  if(environment())
  critters = filter(all_inventory(environment(this_object())), (: living($1) && !newbiep($1) :));
critters = filter(critters, (: noncreatorp :) );
  if (environment()->GetProperty("no attack")) {
    environment(this_object())->eventPrint("%^BOLD%^%^BLUE%^The sky "
        "appears to clear.%^RESET%^");
    eventDestruct();
    return;
    }
  message("my_message", "A large meteor crashes into the ground "
         "and %^RED%^explodes!%^RESET%^", environment());
  if (sizeof(critters))
     critters->eventReceiveDamage(this_object(), HEAT|MAGIC|SHOCK|BLUNT, Damage, 0);

}

