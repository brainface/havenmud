#include <lib.h>
inherit LIB_ITEM;


private string suit;
private int cardValue;
private string desc;

void SetSuit(string suit);
string GetSuit();
int GetCardValue();
void SetCardValue(int value);
void SetDesc(string desc);
string GetDesc();
void SetupCard();

static void create() {
  ::create();
  SetKeyName("card");
  SetShort("a nondescript playing card..");
  SetId( ({ "card" }) );
  SetAdjectives( ({ "weathered" }) );
  SetLong("A card");
  SetMass(5);
  SetValue(10);
  call_out( (: SetupCard :), 0);
}

SetSuit(string thing) {
  suit = thing;
}
GetSuit() {
  return suit;
}
SetCardValue(count) {
  cardValue = count;
}
GetCardValue() {
  return cardValue;
}
SetDesc(text) {
  desc = text;
  SetLong(text);
}
GetDesc() {
  return desc;
}

SetupCard() {
  string valueDesc; // "5","3","knight", etc.

  valueDesc = ""+cardValue;

  switch (cardValue) {
    case 1: valueDesc = "herald";
      break;
    case 2: valueDesc = "deuce";
      break;
    case 11: valueDesc = "knight";
      break;
    case 12: valueDesc = "priest";
      break;
    case 13: valueDesc = "avatar";

      break;
  }

  SetShort("the " + valueDesc + " of " + suit);
  SetId("card",valueDesc + " of " + suit);
  SetLong(desc +"\nIt is the " + valueDesc + " of " + suit + ".");


  AddSave( ({ "suit","cardValue","desc" }) );
}

