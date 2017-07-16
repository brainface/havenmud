#include <lib.h>
#include <damage_types.h>

inherit LIB_ITEM;

string  SetMaster(string master);
int     SetCountDown(int timeLImit);
int     GetCountDown();
void    DoFade();
void    DoPurge();
string  Master = "";
int     countDown;
int     Damage;
int SetDamageAmount(int damage);

static void create() {
        item::create();
        SetKeyName("black circle");
        SetId( ({"circle",}) );
        SetAdjectives( ({"large", "black", "chalk"}) );
        SetShort("a large chalk circle");
        SetLong("This large circle glows with unholy power. It is drawn to so "
        "that it surrounds the room. It is made with black chalk dust, though "
        "it looks like it could be easily destroyed or removed, it remains perfectly "
        "untouched.");
        SetMass(1);
        SetValue(0);
        SetDamagePoints(5);
        SetProperty("gcircle", 1);
        SetPreventGet("You cannot pick that up!");
        set_heart_beat(5);
}

void init() {
  object who;
  if(this_player()->GetKeyName() != Master && !(immortalp(this_player())) && (!newbiep(this_player())))  {           
    if(this_player()->GetMorality() > 200 ) {
      send_messages( "",
           "%^BOLD%^%^BLACK%^The chalk circle glows flares as $agent_name steps into the room.%^RESET%^",
           this_player(), 0, environment());        
      Damage = Damage/5;        
      this_player()->eventReceiveDamage(this_object(), HEAT, Damage, 0);
      if(userp(this_player())) this_player()->eventWimpy();
    }        
  }
}

void heart_beat() {

    object room;
    object who;
    
    room = environment(this_object());

    if (!room) {
     eventDestruct();
     return;
    }  
    if(!who = find_player(Master)){
   room->RemoveProperty("great_circle");
     eventDestruct();
     return;
    }    
        countDown--;
        if(!countDown) { DoFade(); }
        else {

        return DoPurge();
        }
}

string SetMaster(string master)
{
        return (Master = master);
}

int SetCountDown(int timeLimit)
{
        return (countDown = timeLimit);
}

int SetDamageAmount(int damage){
        return (Damage = damage);
}

int GetCountDown()
{
        return countDown;
}

void DoFade()
{
        object who;
        object room3;

        room3 = environment(this_object());
        if(who = find_player(Master))
        message("ward message",
        "%^BOLD%^%^BLUE%^Your Black Circle fades out "
        "of existence at " + room3->GetShort() + ".%^RESET%^",who);
        
        room3->RemoveProperty("great_circle");
        eventDestruct();
}


void DoPurge(){
  object *critters;
  object who;
  who = find_player(Master);
  
  critters = filter(all_inventory(environment(this_object())), (: living($1) && !newbiep($1) :));
  critters = filter(critters, (: noncreatorp :) );
  critters -= who->GetFollowers() + ({ who });
      message("ward message",
              "%^BOLD%^%^RED%^The chalk circle glows red briefly.%^RESET%^", environment());
        critters->eventReceiveDamage(this_object(), HEAT|MAGIC|SHOCK, Damage/5, 0); 
}

