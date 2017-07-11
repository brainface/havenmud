// fear object for maddening visions
// Thoin
// 12-17-05
 

#include <lib.h>
inherit LIB_ITEM;

int SetCountDown(int timeLimit);
int GetCountDown();
void DoFade();
int countDown;

static void create(){
        item::create();
        SetKeyName("fear object");
        SetId( ({"fear_object" }) );
        SetShort("fear object");
        SetLong("A fear causing object.");
        SetInvis(1);
        SetMass(0);
        SetValue(0);
        SetDamagePoints(5);
        SetPreventDrop("You cannot drop that!");
        SetPreventGet("Get what?");
        set_heart_beat(5);
}

void heart_beat(){
    object room;
    object who;
    object NewRoom4;
    string *exits;
    string NewRoom, OldRoom, NewRoom3;
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
    exits = room->GetExits();    
    NewRoom = exits[random(sizeof(exits))];
    NewRoom3 = room->GetExit(NewRoom);
    NewRoom4 = find_object(NewRoom3);
  who->SetSleeping(0);

   environment(this_object())->eventPrint("%^BOLD%^%^RED%^The shadows "
        "melt into nightmares and you run, trying to escape them.%^RESET%^", who);
    who->eventForce("scream fearfully");
    who->eventMove(NewRoom3);
    room->eventPrint(capitalize(who->GetName()) + " runs off to the " + NewRoom + " screaming.", who);
    who->eventDescribeEnvironment();
    NewRoom3->eventPrint(capitalize(who->GetName()) + " enters the room screaming.", who);
        countDown--;
        if(!countDown) { DoFade(); }
}

int SetCountDown(int timeLimit){
        return (countDown = timeLimit);
}

int GetCountDown(){
        return countDown;
}

void DoFade(){
        object who;
        who = environment(this_object());
        environment(this_object())->eventPrint("%^RED%^The maddening visions fade "
        "from your mind.%^RESET%^", who);
        who->RemoveProperty("uncon_fear");
        eventDestruct();
}
