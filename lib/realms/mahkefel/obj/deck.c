#include <lib.h>
#include <std.h>
inherit LIB_ITEM;
#include <vendor_types.h>

class Card {
  string long;
  string suit;
  int value;
}

object CreateCard(class Card card);
class Card GetRandomCard();
int DealCardFaceupTo(object player);
int DealCardFacedownTo(object player);
int DrawCardFaceup();
int DrawCardFacedown();

int draw(string args);
int deal(string args);
int shuffle(string args);
// todo:
int ShuffleCardIntoDeck(object card);

mixed CanPutInto(object who, object item);

// suits:
// ghouls 0
// blades 1
// scales 2
// roses  3

// herald A
// knight J
// priest Q
// avatar K
      
private class Card* cards =({
  // ghouls
  new(class Card, suit : "ghouls", value :  1, long : "A hanged man strung from a dead tree."),
  new(class Card, suit : "ghouls", value :  2, long : "Two grinning skulls."),
  new(class Card, suit : "ghouls", value :  3, long : "Three grinning skulls."),
  new(class Card, suit : "ghouls", value :  4, long : "Four grinning skulls."),
  new(class Card, suit : "ghouls", value :  5, long : "Five grinning skulls"),
  new(class Card, suit : "ghouls", value :  6, long : "Six grinning skulls in a circle."),
  new(class Card, suit : "ghouls", value :  7, long : "Seven grinning skulls."),
  new(class Card, suit : "ghouls", value :  8, long : "Two rows of four grinning skulls."),
  new(class Card, suit : "ghouls", value :  9, long : "Nine grinning skulls in a circle."),
  new(class Card, suit : "ghouls", value : 10, long : "Two columns of five grinning skulls."),
  new(class Card, suit : "ghouls", value : 11, long : "A nosferatu clad in black plate, sword dripping blood."),
  new(class Card, suit : "ghouls", value : 12, long : "A stunning vampiress, pale corpse lying bloodless at her feet."),
  new(class Card, suit : "ghouls", value : 13, long : "A lich atop a dark tower, armies of ghouls gathered below."),

  // blades
  new(class Card, suit : "blades", value :  1, long : "A bright-eyed drummer boy on the march. Stormclouds gather above ominously."),
  new(class Card, suit : "blades", value :  2, long : "Two deulists clashing with rapiers"),
  new(class Card, suit : "blades", value :  3, long : "Three painted swords in a triangle."),
  new(class Card, suit : "blades", value :  4, long : "Four painted swords facing outwards in a cross."),
  new(class Card, suit : "blades", value :  5, long : "Five painted swords facing outwards."),
  new(class Card, suit : "blades", value :  6, long : "Two rows of three painted swords."),
  new(class Card, suit : "blades", value :  7, long : "A row of three and four painted swords."),
  new(class Card, suit : "blades", value :  8, long : "Two rows of four painted swords facing each other."),
  new(class Card, suit : "blades", value :  9, long : "Three rows of three painted swords."),
  new(class Card, suit : "blades", value : 10, long : "Two circles of five painted swords."),
  new(class Card, suit : "blades", value : 11, long : "A dashing swordsman with shield raised."),
  new(class Card, suit : "blades", value : 12, long : "An elven sorceress with glowing eyes and hands aflame."),
  new(class Card, suit : "blades", value : 13, long : "A screaming woman wielding blades in six arms and perched upon a serpentine tail."),

  // scales
  new(class Card, suit : "scales", value :  1, long : "A tabarded minstrel blowing a bugle at the skies."),
  new(class Card, suit : "scales", value :  2, long : "A set of scales with two pans."),
  new(class Card, suit : "scales", value :  3, long : "A set of scales with three pans."),
  new(class Card, suit : "scales", value :  4, long : "A set of scales with two pans on each side."),
  new(class Card, suit : "scales", value :  5, long : "A complex set of scales with five pans."),
  new(class Card, suit : "scales", value :  6, long : "A set of scales with three pans on each side."),
  new(class Card, suit : "scales", value :  7, long : "A complex set of scales with seven pans."),
  new(class Card, suit : "scales", value :  8, long : "A set of scales with four tiny pans on each side."),
  new(class Card, suit : "scales", value :  9, long : "A ridiculous set of scales with nine pans."),
  new(class Card, suit : "scales", value : 10, long : "An intricate and complex set of scales with ten pans of various sizes."),
  new(class Card, suit : "scales", value : 11, long : "An elven paladin in shining plate, swords gleaming under a painted sun."),
  new(class Card, suit : "scales", value : 12, long : "An elven maiden clothed in white, simultaneously resurrecting a fallen hero and banishing a demon."),
  new(class Card, suit : "scales", value : 13, long : "A dragon roaring flame, surrounded by smoking corpses in a dark cavern."),

  // roses
  new(class Card, suit : "roses", value :  1, long : "A skaven thief crawling through a mansion window, dragging a bag spilling jewels and chalices."),
  new(class Card, suit : "roses", value :  2, long : "Two black roses entwined."),
  new(class Card, suit : "roses", value :  3, long : "Three black roses."),
  new(class Card, suit : "roses", value :  4, long : "Two pairs of black roses entwined."),
  new(class Card, suit : "roses", value :  5, long : "Five black roses facing outward."),
  new(class Card, suit : "roses", value :  6, long : "Three pairs of black roses entwined."),
  new(class Card, suit : "roses", value :  7, long : "Seven black roses facing outward."),
  new(class Card, suit : "roses", value :  8, long : "Four pairs of black roses entwined."),
  new(class Card, suit : "roses", value :  9, long : "Three sets of three black roses entwined."),
  new(class Card, suit : "roses", value : 10, long : "Ten black roses entwined in a circle."),
  new(class Card, suit : "roses", value : 11, long : "A buxom, sneering darkelf twirling a rapier, black flag swirling above."),
  new(class Card, suit : "roses", value : 12, long : "A haughty dark elf in elegant robes, standing before an altar piled with dark roses."),
  new(class Card, suit : "roses", value : 13, long : "A lithe demoness perched atop a pile of shimmering gold."),  
});


static void create() {
  ::create();
  SetKeyName("deck of cards");
  SetId( ({ "deck" }) );
  SetAdjectives( ({ "deck","of" }) );
  SetShort("a deck of weathered playing cards");
  SetLong("A well-travelled deck of dog-eared playing cards. A colorful, "
    "if faded, painting of rogues and knights and various monsters "
    "all fighting adorns the outside."
    "\nA set of instructions appear to be written on the back."
    );
  SetMass(10);
  SetValue(1000);
  SetVendorType(VT_TREASURE);

  SetDamagePoints(500);
  SetMaterial( ({ "textile" }) );
  SetRepairSkills( ([ "textile" : 1,]) );
  SetRepairDifficulty(20);
  //SetCanClose(0);
  //SetMaxCarry(250);
  SetRead("default",
    "draw card faceup\n"
    "draw card facedown\n"
    "deal card faceup to <person>\n"
    "deal card facedown to <person>\n"
    "shuffle <card> in\n"
    "glance at cards to not reveal? (TODO)\n"
  );
}
void init() {
  ::init();
  add_action("draw","draw");
  add_action("deal","deal");
  add_action("shuffle","shuffle");
}

int draw(string args) { 
  if (!args) {
    message("system", "Perhaps you should read the instructions <read deck>.",
    this_player() );
    return 1;
  }
  if (args == "card faceup") {
    DrawCardFaceup();
    return 1;
  }
  if (args == "card facedown") {
    DrawCardFacedown();
    return 1;
  }
  return 0;
}
  
int deal(string args) {
  string dealeeName = "";
  object dealee;
  
  if (!args) {
    message("system", "Perhaps you should read the instructions <read deck>.",
    this_player() );
    return 1;
  }
  if (strsrch(args,"card faceup to") != -1) {
    dealeeName = replace_string(args, "card faceup to ", "");
    dealee=present(dealeeName, environment(this_player()));
    if(!dealee) {
      this_player()->eventPrint("You can't seem to find " + dealeeName + ".");
      return 0;
    }
    DealCardFaceupTo(dealee);
    return 1;
  }
  if (strsrch(args,"card faceup to") != -1) {
    dealeeName = replace_string(args, "card facedown to ", "");
    dealee=present(dealeeName, environment(this_player()));
    if(!dealee) {
      this_player()->eventPrint("You can't seem to find " + dealeeName + ".");
      return 0;
    }
    DealCardFacedownTo(dealee);
    return 1;
  }
  return 0;
}

object CreateCard(class Card card) {
   object playingCard;
   string short;
   string long;
   string value;
   
   playingCard = new(STD_OBJ "card");

   playingCard->SetSuit(card->suit);        
   playingCard->SetCardValue(card->value);
   playingCard->SetDesc(card->long);
   playingCard->SetupCard();
   
   return playingCard;
}

class Card GetRandomCard() {
  class Card card;
  
  if (!sizeof(cards)) return 0;
  
  card = cards[random(sizeof(cards))];
  cards -= ({card});
  return card;
}

int DrawCardFaceup() {
  class Card card;
  object playingCard;
  
  if (card = GetRandomCard()) {
    playingCard = CreateCard(card);
    playingCard->eventMove(this_player());
    send_messages( ({"draw","reveal"}), "$agent_name $agent_verb and $agent_verb " + playingCard->GetShort(),
      this_player(), 0, environment(this_player()) ); 
    
  } else {
    send_messages( ({"try"}), "$agent_name $agent_verb to draw a card from an empty deck.",
      this_player(), 0, environment(this_player()) );
    this_player()->eventPrint("There are no cards left in the deck!");
  }
}

int DrawCardFacedown() {
  class Card card;
  object playingCard;
  
  if (card = GetRandomCard()) {
    playingCard = CreateCard(card);
    playingCard->eventMove(this_player());
    send_messages( ({"draw","slide"}), "$agent_name $agent_verb a card facedown and slides it into $agent_possessive_noun hand.",
      this_player(), 0, environment(this_player()) ); 
    
  } else {
    send_messages( ({"try"}), "$agent_name $agent_verb to draw a card from an empty deck.",
      this_player(), 0, environment(this_player()) );
    this_player()->eventPrint("There are no cards left in the deck!");
  }
}

int DealCardFacedownTo(object who) {
  class Card card;
  object playingCard;
  
  if (card = GetRandomCard()) {
    playingCard = CreateCard(card);
    playingCard->eventMove(who);
    send_messages( ({"draw","deal"}), "$agent_name $agent_verb a card and $agent_verb it facedown to $target_name.",
      this_player(), who, environment(this_player()) ); 
  } else {
    send_messages( ({"try"}), "$agent_name $agent_verb to draw a card from an empty deck.",
      this_player(), 0, environment(this_player()) );
    this_player()->eventPrint("There are no cards left in the deck!");
  }
}

int DealCardFaceupTo(object who) {
  class Card card;
  object playingCard;
  
  if (card = GetRandomCard()) {
    playingCard = CreateCard(card);
    playingCard->eventMove(who);
    send_messages( ({"draw","reveal","deal"}), "$agent_name $agent_verb and $agent_verb " + playingCard->GetShort() +
      ", then $agent_verb it faceup to $target_name",
      this_player(), who, environment(this_player()) ); 
    
  } else {
    send_messages( ({"try"}), "$agent_name $agent_verb to draw a card from an empty deck.",
      this_player(), 0, environment(this_player()) );
    this_player()->eventPrint("There are no cards left in the deck!");
  }
}

int ShuffleCardIn(object playingCard) {
  if (!playingCard->GetSuit()) {
    this_player()->eventPrint("that's not a card!");
    return 0;
  }
  if (!playingCard->GetCardValue()) {
    this_player()->eventPrint("that's not a card!");
    return 0;
  }
  if (!playingCard->GetDesc()) {
    this_player()->eventPrint("that's not a card!");
    return 0;
  }
  cards += ({ new (class Card, suit: playingCard->GetSuit(), value: playingCard->GetCardValue(), long: playingCard->GetDesc()) });
  send_messages( ({"shuffle"}), "$agent_name $agent_verb a card into the deck.",
    this_player(), 0, environment(this_player()) ); 
  playingCard->eventDestruct();
  return 1;  
}

int shuffle(string args) {
  string cardName = "";
  object playingCard;
  
  if (!args) {
    message("system", "Perhaps you should read the instructions <read deck>.",
    this_player() );
    return 0;
  }
  cardName = replace_string(args, " in", "");
  playingCard=present(cardName, this_player());
  if(!playingCard) {
    this_player()->eventPrint("You can't seem to find the " + cardName + ".");
    return 0;
  }
  ShuffleCardIn(playingCard);
  return 1;
}

