// Milor, he likes to roll dice

#include <lib.h>
#include <std.h>
inherit LIB_NPC;

int Funds = 0;
string Owner;
string LocalCurrency = "shrydes";
string ID;
int MinBet = 400;

int currentBet;
int currentNumber;
int currentTotal;
int MaxBet;
int betnumber;
int thisnumber;
int done;
int throw;
int busy;

void Restore();
void Save();

int PickBet(string inputBet);
int PickNumber(string inputNumber);

static void create() {
  ::create();
  if (ID) Restore();
  
  SetKeyName("milor");
  SetShort("Milor the Shrewd Gambler");
  SetId( ({ "milor", "gambler" }) );
  SetAdjectives( ({"shrewd"}) );
  SetLong(
    "Milor is a tall old dark-elf with extraordinarily long hair, extending "
    "almost to his waist. His aged face is rather wrinkled, though he still "
    "manages to display an air of charisma. He seems like a cheerful, "
    "friendly man, though like most dark-elves, worthy of some caution."      
  );  
  SetRace("dark-elf");
  SetClass("fighter");
  SetLevel(50);
  SetGender("male");
  SetReligion("soirin");
  SetBaseLanguage("Eltherian");
  SetMorality(-400);  
  SetAction(6, ({
    "!say Want to play some dice?",
    "!emote sniffles and quickly rubs his nose.",    
  }) );  
  busy = 0;
 }

int AddFunds(int x) { Funds += x; Save(); return Funds; }
int GetFunds() { return Funds; }
int SetFunds(int x) { Funds = x; Save(); return Funds; }

string SetOwner(string x) { Owner = x; Save(); return GetOwner(); }
string GetOwner() { return Owner; }

int SetMinBet(int x) { MinBet = x; Save(); return MinBet; }
int GetMinBet() { return MinBet; }

void Save() {
  if (!ID) return;
  save_object(DIR_SAVE "/gambler/" + ID + ".o");
}

void Restore() {
  if (!ID) return;
  restore_object(DIR_SAVE "/gambler/" + ID + ".o");
}

string SetLocalCurrency(string x) { return LocalCurrency = x; }
string GetLocalCurrency() { return LocalCurrency; }

string SetID(string x) { ID = x; Restore(); return ID; }
string GetID() { return ID; }

string GetLong() {
  if (!GetOwner() || GetOwner() == "" ) return ::GetLong();
  return capitalize(GetKeyName()) + " works for " + capitalize(GetOwner()) 
    + ". " + ::GetLong();
}

int eventSet(object who, string what) {
  string to, fr;
  sscanf(what, "%s to %s", what, to);
  sscanf(what, "%s for %s", what, fr);
  if (who->GetKeyName() != GetOwner()) {
    eventForce("speak Sorry, you're not the owner of this establishment.");
    return 1;
    }
  eventForce("speak Setting " + what + " for " + fr + " to " + to);
  if (what == "owner") {
    SetOwner(lower_case(to));
    eventForce("speak I now listen only to " + capitalize(to));
    return 1;
  }
  if (what == "minbet") {
    SetMinBet(to_int(to));
    eventForce("speak Minimum bet changed to " + to + " shrydes.");
    return 1;
  }  
  return 1;
}

void eventReport(object who) {
  string own;
  if (who->GetKeyName() != GetOwner() && !sagep(who)) {
    eventForce("speak I don't work for you.");
    return;
  }
  if (who->GetGender() == "female") own = "Mistress"; else own = "Sir";
  eventForce("speak " + own + ", the betting funds stand at " + Funds + " " +
             LocalCurrency);
  send_messages( ({ "hand" }),
    "$agent_name $agent_verb over a summary page to $target_name.",
    this_object(), who, environment() );
  who->eventPrint("Summary details (in " + LocalCurrency + ") ");
  who->eventPrint("The minimum bet is set to " + GetMinBet() + ".");  
  who->eventPrint("Owner: " + (GetOwner() ? capitalize(GetOwner()) : "No-one"));
}

int eventDeposit(object who, int amount) {
  if (who->GetKeyName() != GetOwner()) {
    eventForce("speak Much as I'd like your money, it isn't possible.");
    return 1;
    }
  if (who->GetCurrency(LocalCurrency) < amount) {
    who->eventPrint("You don't have that much in " + LocalCurrency + ".");
    return 1;
  }
  AddFunds(amount);
  who->AddCurrency(LocalCurrency, -amount);
  eventReport(who);
  return Funds;
}

int eventWithdraw(object who, int amount) {
  if (who->GetKeyName() != GetOwner()) {
    eventForce("speak I don't work for you. But if you need money, have a game!.");
    return 1;
    }
  if (Funds < amount) {
    who->eventPrint("We don't have that much in " + LocalCurrency + ".");
    return 1;
  }
  AddFunds(-amount);
  who->AddCurrency(LocalCurrency, amount);
  eventReport(who);
  return Funds;
}

mixed eventAsk(object who, string args) {
  string action, what;
  string *tmp = ({ });
  sscanf(args, "%s %s", action, what);
  if (!action) action = args;

  if (action == "play") {
    if (busy == 1)
    {
    	eventForce("speak I'm in the middle of a game here, wait your turn.");
    	return 1;
    }
    if (GetFunds() < (MinBet * 4))
    {
      eventForce("speak Sorry, I don't have the money to play right now. Come "
        "back later after I've spoken to the boss.");
      return 1;
    }
    busy = 1;
    eventForce("speak Alright then, let's play some dice.");
    MaxBet = GetFunds() / 4;
    who->eventPrint("Enter your bet (in " + GetLocalCurrency() + ") or input "
      "'exit' to cancel. The maximum bet for this game is " + MaxBet + " " + 
      GetLocalCurrency() + ".");
    input_to( (: PickBet :) );
    return 1;
  }
  
  if (action == "explain") {
    eventForce("speak It's simple! You place your bet, and pick a number "
      "between 14 and 18. We roll the dice until we get a total number over 12. "
      "If we get 13, you lose. 13 is unlucky, see. If we get the number you "
      "picked, you win back double what you bet. Get it?");
      return 1;
   }
    
  /* Owner Functions */
  if (action == "set") return eventSet(who, what);
  if (action == "report") return eventReport(who);
  if (action == "deposit") return eventDeposit(who, to_int(what));
  if (action == "withdraw") return eventWithdraw(who, to_int(what));
  eventForce("speak Eh? You aren't making sense. Did you want to play? "
    "Or did you want me to explain the rules?");  
  if (GetOwner() == who->GetKeyName()) 
    eventForce("speak You could also ask me to withdraw AMOUNT, deposit "
               "AMOUNT, or report. You could also ask me to set owner to NAME "
               "to sell the business.");
  return 1;
}

int PickBet(string inputBet) {
  object who = this_player();
  if(inputBet=="exit") {
  	busy = 0;
  	return 0;
  }
  betnumber = to_int(inputBet);
  if (who->GetCurrency(GetLocalCurrency()) < betnumber) {
    who->eventPrint("You don't have that much in " + GetLocalCurrency() + ".");
    busy = 0;
    return 1;
  }
  
  if (betnumber < GetMinBet())
  { 
    eventForce("speak You didn't bet enough. Come back when you can afford "
      "to play me.");
      busy = 0;
    return 1;
  }
  
  if (betnumber > MaxBet) 
  {
    eventForce("speak Hey, I'm not made of money. The maximum bet I can afford "
      "is " + MaxBet + " " + GetLocalCurrency() + "!");
      busy = 0;
    return 1;
  }
  
  if (betnumber > 100000)
  {
    eventForce("speak Ooh, I love it when the stakes are high!");
  }
  
  currentBet = betnumber;
  
  who->eventPrint("Please pick a number between 14 and 18 to begin the game, "
    "or input 'exit' to cancel.");
  input_to( (: PickNumber :) );
  return 1;
}

int PickNumber(string inputNumber) {
  object who = this_player();
  if(inputNumber=="exit") 
  {
    currentBet = 0;
    busy = 0;
    return 1;
  }
  
  thisnumber = to_int(inputNumber);
  if (thisnumber < 14)
  {
    who->eventPrint("Number must be greater than 13 and less then 19");
    input_to( (: PickNumber :) );
    currentBet = 0;
    return 1;
  }
  
  if (thisnumber > 18)
  {
    who->eventPrint("Number must be greater than 13 and less then 19");
    input_to( (: PickNumber :) );
    currentBet = 0;
    return 1;
  }
  
  currentNumber = thisnumber;
  eventForce("speak Alright, here we go!");
  done = 0;
  throw = 0;
  while (done == 0)
  {
    throw = random(5)+1;
    eventForce("emote rolls a little red die. It lands on " + throw + "!");
    currentTotal += throw;
    
    if (currentTotal > 12)
    {
      if (currentTotal == currentNumber)
      {
        eventForce("speak " + currentNumber + "! Nicely done. You win " + 
          currentBet*2 + " " + GetLocalCurrency() + "! Hey, want another game? "
          "I need a chance to win all that money back!");
        AddFunds(-(currentBet*2));
        who->AddCurrency(GetLocalCurrency(), currentBet*2);
        currentBet = 0;
        currentTotal = 0;
        currentNumber = 0;
        done = 1;
        busy = 0;
        return 1;
      }
      
      eventForce("speak Ohh, unlucky! You got " + currentTotal + ", you "
        "lose. Better luck next time!");
      AddFunds(currentBet);
      who->AddCurrency(GetLocalCurrency(), -currentBet);
      currentBet = 0;
      currentTotal = 0;
      currentNumber = 0;
      done = 1;
      busy = 0;
      return 1;
    }
  }
  return 1;
}

  