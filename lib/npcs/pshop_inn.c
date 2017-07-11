//

// /lib/pshop_inn.c

// An Inkeeper for player shops

// Created by Zaxan@Haven

// Version: 3.0

//



#include <lib.h>
#include <clock.h>
#include <meal_types.h>
#include <daemons.h>

inherit LIB_BARKEEP;

int GetPrice(object, int);
int eventBuy(object, string);
varargs int cmdList(object, string, string);
int cmdBuy(object, string, string);
int cmdPrice(object who, string args);
int SetWage(int);
int GetWage();
void eventDoWage();
private int wage;
private int heart_beat_wage = DAY;

static void create() {
   barkeep::create();
   SetShort("the local innkeeper");
   SetLong("This large innkeeper is waiting for someone to ask for "
           "his services.");
   SetAdjectives( ({ "large", "local" }) );
   SetGender("male");

   SetId( ({ "barkeep", "innkeep", "innkeeper" }) );
   SetKeyName("innkeeper");
   SetClass("rogue");
   SetLevel(15);
   SetWage(10);
   set_heart_beat(1);
}

void heart_beat() {
   heart_beat_wage--;
   if(!heart_beat_wage) { eventDoWage(); }
   return barkeep::heart_beat();
}

mixed indirect_sell_obj_to_liv() {
   return "Wouldn't you rather <ask> " + objective(this_object()) + " <to buy> it?";
}

int SetWage(int x) {
   return (wage = x);
}

int GetWage() {
   return wage;
}

mixed eventAsk(object who, string str) {
   string cmd, args;

   if(!str||str=="") {
      eventForce("speak How may I help you?");
      return 1;
   }
   if(sscanf(str,"%s %s",cmd,args) != 2) {
      cmd = str;
      args = 0;
   }
   if (GetInCombat()) {
      eventForce("I am a little busy right now!");
      return 1;
   }
   switch (cmd) {
      case "list" : case "show" : case "browse" :
         cmdList(0, 0, args);
         break;
      case "sell" : case "serve" :
         cmdBuy(who, 0, args);
         break;
      case "buy" :
          eventBuy(who, args);
          break;
      case "price" :
          cmdPrice(who, args);
          break;

      default :

          eventForce("speak I'm not exactly sure what "

                     "you're asking me.");

          break;

   }

   return 1;

}



void eventDoWage() {

   int funds = environment()->GetStoreFunds();

   float x = (currency_rate(environment()->GetLocalCurrency()));

   int amount = (x * GetWage());

   amount = to_int(amount);



   if(funds < amount) {

      environment()->AddMad(1);

      heart_beat_wage = DAY;

   } else {

      environment()->AddStoreFunds(-amount);

      heart_beat_wage = DAY;

   }

   if(environment()->GetMad() >= 3) {

      environment()->SetBarkeep(0);

      environment()->SetMad(0);

      this_object()->eventDestruct();

   }

}



int eventBuy(object who, string args) {

   object corpse;

   int x, unique;



   if(!args || args == "") {

      eventForce("speak what do you want me to buy?");

      return 1;

   }

   if(present(args, who)) {

      corpse = present(args, who);

   }

   if(!corpse) {

      eventForce("speak you don't have that!");

      return 1;

   }

   if(member_array("corpse", corpse->GetId()) == -1) {

      eventForce("speak I only buy corpses");

      return 1;

   }

   if(member_array(corpse->GetRace(), keys(environment()->GetPayOuts())) == -1) {

      if(member_array(corpse->GetRace(), RACES_D->GetRaces()) != -1) {

         eventForce("speak I don't purchase corpses of "

                    "that race.");

         return 1;

      }

      if( (member_array(corpse->GetRace(), RACES_D->GetRaces()) == -1) &&

          (member_array("unique", keys(environment()->GetPayOuts())) == -1) ) {

         eventForce("speak I don't purchase corpses of "

                    "that race.");

         return 1;

      }

      unique = 1;

   }

   if(unique) {

      x = environment()->GetPayOut("unique");

   } else x = environment()->GetPayOut(corpse->GetRace());

   if((environment()->GetStoreFunds()) < x) {

      eventForce("speak I'm sorry, but the shop is having "

                 "financial difficulties right now.");

      return 1;

   }

   who->AddCurrency(GetLocalCurrency(), x);

   environment()->AddStoreFunds(-x);

   environment()->AddMeatPoints( (corpse->GetStrength() * 4) );

   corpse->eventDestruct();

   eventForce("speak Thank you for your business! Come "

              "back soon!");

   return 1;

}



int cmdPrice(object who, string args) {

   int price;



   if(!args || args == "") {

      eventForce("speak what would you like me to price?");

      return 1;

   } else if(args == "meat") {

      eventForce("speak err, could you be a little more "

                 "specific?");

      return 1;

   } else if(args == "piece" ||

             args == "small piece" ||

             args == "small piece of meat" ||

             args == "piece of meat" ||

             args == "a piece of meat" ||

             args == "a small piece of meat") {

      price = GetPrice(who, environment()->GetMeatCost("weak"));

      eventForce("speak I will sell you "+args+" for "+price+" "

                 +GetLocalCurrency()+".");

      return 1;

   } else if(args == "slice" ||

             args == "slice of meat" ||

             args == "a slice of meat") {

      price = GetPrice(who, environment()->GetMeatCost("medium"));

      eventForce("speak I will sell you "+args+" for "+price+" "

                 +GetLocalCurrency()+".");

      return 1;

   } else if(args == "chunk" ||

             args == "large chunk" ||

             args == "large chunk of meat" ||

             args == "chunk of meat" ||

             args == "a chunk of meat" ||

             args == "a large chunk of meat") {

      price = GetPrice(who, environment()->GetMeatCost("strong"));

      eventForce("speak I will sell you "+args+" for "+price+" "

                 +GetLocalCurrency()+".");

      return 1;

   } else if(environment()->GetSaleInventory()[args]) {

      price = GetPrice(who, environment()->GetSaleCost(args));

      eventForce("speak I will sell you "+args+" for "+price+" "

                 +GetLocalCurrency()+".");

   } else {

      eventForce("speak I don't have anything like that to sell.");

      return 1;

   }

}



varargs int cmdList(object who, string cmd, string args) {
   mapping Pay = ([ ]);

   string *payArray = ({});

   string *list = ({});

   int i, maxi;



   maxi = sizeof(environment()->GetSaleInventory());

   if(args == "payouts") {

      foreach(string race in keys(environment()->GetPayOuts())) {

         Pay[race] = environment()->GetPayOut(race);

      }

      foreach(string race in keys(Pay)) {

         payArray += ({ race + " for " + Pay[race] });

      }

      if(!sizeof(payArray)) {

         eventForce("speak I'm not accepting any corpses right now. "

                    "Sorry!");

         return 1;

      } else {

         eventForce("speak I currently accept the following races: "

                    +conjunction(payArray)+".");

         eventForce("speak All payouts are done in "

                    +GetLocalCurrency()+" of course.");

         return 1;

      }

   }

   list = ({ " #  Description", "" });

   i = (int)this_player()->GetScreen()[0];

   while( i-- ) list[1] += "_";

   for(i=0; i<maxi; i++) {

      list += ({ sprintf("%:-3d %s", (i+1),

                 keys(environment()->GetSaleInventory())[i]) });

   }

   if(environment()->GetMeat("weak")) {

      i++;

      list += ({ sprintf("%:-3d %s", i, "a small piece of meat") });

   }

   if(environment()->GetMeat("medium")) {

      i++;

      list += ({ sprintf("%:-3d %s", i, "a slice of meat") });

   }

   if(environment()->GetMeat("strong")) {

      i++;

      list += ({ sprintf("%:-3d %s", i, "a large chunk of meat") });

   }

   this_player()->eventPage(list);

}



varargs int cmdBuy(object who, string cmd, string args) {
   object thing;

   int cost;

   int wvalue = environment()->GetMeatCost("weak");

   int mvalue = environment()->GetMeatCost("medium");

   int svalue = environment()->GetMeatCost("strong");

   int maxw = environment()->GetMeat("weak");

   int maxm = environment()->GetMeat("medium");

   int maxs = environment()->GetMeat("strong");



   if(!args || args == "") {

      eventForce("speak err, what do you want me to sell?");

      return 1;

   } else if(args == "meat") {

      eventForce("speak err, could you be a little more "

                 "specific?");

      return 1;

   } else if(args == "piece" ||

             args == "small piece" ||

             args == "small piece of meat" ||

             args == "piece of meat" ||

             args == "a piece of meat" ||

             args == "a small piece of meat") {

      cost = GetPrice(who, wvalue);

      if(!maxw) {

         eventForce("speak I don't have anything like that "

                    "to sell");

         return 1;

      }

      if(cost > who->GetCurrency(GetLocalCurrency())) {

         eventForce("speak You don't have enough money! It costs "+

                    cost+" "+GetLocalCurrency()+".");

         return 1;

      }

      thing = new(LIB_PSHOP_MEAL);

      thing->SetKeyName("small meat");

      thing->SetShort("a small piece of meat");

      thing->SetId( ({ "meat", "piece of meat" }) );

      thing->SetLong("This small piece of meat looks very good to eat.");

      thing->SetAdjectives(({ "small", "piece" }) );

      thing->SetMass(5);

      thing->SetMealType(MEAL_FOOD);

      thing->SetStrength(15);

      thing->SetMealMessages("The meat feels very good in your belly.",

                             "$N eats a small piece of meat.");

      thing->eventMove(this_object());

      environment()->AddMeat("weak", -1);

      eventForce("give " + (string)thing->GetKeyName() + " to " +

                 (string)who->GetKeyName());

      if( environment(thing) == this_object() ) {

         eventForce("speak heh, you cannot carry that. I will drop it.");

         eventForce("drop " + (string)thing->GetKeyName());

         if( environment(thing) == this_object()) {

            thing->eventMove(environment());

         }

      }

      eventForce("speak Thanks for your business!");

      who->AddCurrency(GetLocalCurrency(), -cost);

      who->AddStoreFunds(cost);

      return 1;

   } else if(args == "slice" ||

             args == "slice of meat" ||

             args == "a slice of meat") {

      cost = GetPrice(who, mvalue);

      if(!maxm) {

         eventForce("speak I don't have anything like that to sell");

         return 1;

      }

      if(cost > who->GetCurrency(GetLocalCurrency())) {

         eventForce("speak You don't have enough money! It costs "+

                    cost+" "+GetLocalCurrency()+".");

         return 1;

      }

      thing = new(LIB_PSHOP_MEAL);

      thing->SetKeyName("medium meat");

      thing->SetShort("a slice of meat");

      thing->SetId( ({ "meat", "slice of meat" }) );

      thing->SetLong("This slice of meat looks very good to eat.");

      thing->SetAdjectives(({ "slice" }) );

      thing->SetMass(10);

      thing->SetMealType(MEAL_FOOD);

      thing->SetStrength(30);

      thing->SetMealMessages("The meat feels very good in your belly.",

                             "$N eats a slice of meat.");

      thing->eventMove(this_object());

      environment()->AddMeat("medium",-1);

      eventForce("give " + (string)thing->GetKeyName() + " to " +

                 (string)who->GetKeyName());

      if( environment(thing) == this_object() ) {

         eventForce("speak heh, you cannot carry that. I will drop it.");

         eventForce("drop " + (string)thing->GetKeyName());

         if( environment(thing) == this_object()) {

            thing->eventMove(environment());

         }

      }

      eventForce("speak Thanks for your business!");

      who->AddCurrency(GetLocalCurrency(), -cost);

      environment()->AddStoreFunds(cost);

      return 1;

   } else if(args == "chunk" ||

             args == "large chunk" ||

             args == "large chunk of meat" ||

             args == "chunk of meat" ||

             args == "a chunk of meat" ||

             args == "a large chunk of meat") {

      cost = GetPrice(who, svalue);

      if(!maxs) {

         eventForce("speak I don't have anything like that to sell");

         return 1;

      }

      if(cost > who->GetCurrency(GetLocalCurrency())) {

         eventForce("speak You don't have enough money! It costs "+cost+" "

                    +GetLocalCurrency()+".");

         return 1;

      }

      thing = new(LIB_PSHOP_MEAL);

      thing->SetKeyName("large meat");

      thing->SetShort("a large chunk of meat");

      thing->SetId( ({ "meat", "chunk of meat" }) );

      thing->SetLong("This large chunk of meat looks very good to eat.");

      thing->SetAdjectives(({ "large", "chunk" }) );

      thing->SetMass(15);

      thing->SetMealType(MEAL_FOOD);

      thing->SetStrength(50);

      thing->SetMealMessages("The meat feels very good in your belly.",

                             "$N eats a large chunk of meat.");

      thing->eventMove(this_object());

      environment()->AddMeat("strong", -1);

      eventForce("give " + (string)thing->GetKeyName() + " to " +

                 who->GetKeyName());

      if( environment(thing) == this_object() ) {

         eventForce("speak heh, you cannot carry that. I will drop it.");

         eventForce("drop " + (string)thing->GetKeyName());

            if( environment(thing) == this_object()) {

               thing->eventMove(environment());

            }

      }

      eventForce("speak Thanks for your business!");

      who->AddCurrency(GetLocalCurrency(), -cost);

      environment()->AddStoreFunds(cost);

      return 1;

   } else if(environment()->GetSaleInventory()[args]) {

      cost = GetPrice(who, environment()->GetSaleCost(args));



      if(cost > who->GetCurrency(GetLocalCurrency())) {

         eventForce("speak You don't have enough money! It costs "+cost+" "

                    +GetLocalCurrency()+".");

         return 1;

      }

      if(!(thing = new(environment()->GetSaleInventory()[args]["filename"]))) {

         eventForce("!speak Uhm, I'm having some difficulty with that.");

         return 1;

      }

      if(environment()->GetSaleInventory()[args]["number"] > 1) {

         environment()->AddSaleInventory(args, -1);

      } else environment()->RemoveSaleInventory(args);

      thing->eventMove(this_object());

      eventForce("give " + (string)thing->GetKeyName() + " to " +

                 who->GetKeyName());

      if( environment(thing) == this_object() ) {

         eventForce("speak heh, you cannot carry that. I will drop it.");

         eventForce("drop " + (string)thing->GetKeyName());

            if( environment(thing) == this_object()) {

               thing->eventMove(environment());

            }

      }

      eventForce("speak Thanks for your business!");

      who->AddCurrency(GetLocalCurrency(), -cost);

      environment()->AddStoreFunds(cost);

      return 1;

   } else {

      eventForce("speak I don't have anything like that to sell.");

      return 1;

   }

}



varargs int eventDie(object agent) {

   environment()->SetInnkeep(0);

   environment()->SetMad(0);

   if(agent) environment()->SetKiller(agent->GetKeyName());

   return barkeep::eventDie(agent);

}



int GetPrice(object who, int amt) {

    return amt;

}
