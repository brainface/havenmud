#include <lib.h>
inherit LIB_NPC;
#include "../hiker.h"

int x;
int y;
int TellStory();
void SpeakStory();

static void create() {
   npc::create();
   SetProperty("hikernoleave",1);
   switch(random(2)) {
      case 0:
      SetGender("male");
      break;
      case 1:
      SetGender("female");
      break;
   }
   SetKeyName("campfire storyteller");
   SetShort("a campfire storyteller");
   SetId( ({ "teller","storyteller","camper" }) );
   SetAdjectives( ({ "campfire","fire","camp","story" }) );
   SetLong("This camper has struck up a new business in the art of "
           "storytelling.  Old campfires are the perfect place to "
           "participate in this activity, and " + nominative(this_object())
           + " seems to have figured this one out.  The storyteller "
           "is tall but skin-and-bones skinny, too, yet something "
           "about " + objective(this_object()) + " suggests that there "
           "is more than meets the eye.");
   switch(random(8)) {
      case 0:
      SetRace("muezzin");
      x = 1; 
      break;
      case 1:
      SetRace("elf");
      x = 1;
      break;
      case 2:
      SetRace("gelfling");
      x = 1;
      break;
      case 3:
      SetRace("dwarf");
      x = 3;
      break;
      case 4:
      SetRace("human");
      x = 2;
      break;
      case 5..7:
      SetRace("halfling");
      x = random(3)+1;
      break;
   }
   SetClass("evoker");
   SetLevel(25+random(3));
   SetSpellBook( ([
                    "enhanced fireball" : 100,
                    "aura"               : 100,
                    "buffer"             : 100,
                    "acid blast"         : 100,
                    "fireball"           : 100,
                    "chain lightning"    : 100,
               ]) );
   SetAction(25, (: TellStory :) );
   SetCombatAction(25, ({
                          "!cast enhanced fireball",
                          "!cast enhanced fireball",
                          "!cast enhanced fireball",
                          "!cast enhanced fireball",
                          "!cast aura",
                          "!cast buffer",
                          "!cast acid blast",
                          "!cast fireball",
                          "!cast chain lightning",
                     }) );
   SetEncounter((:TellStory:));
}

void TellStory() {
   if(!x) x = 1;
   if(!y) {
      y = 0;
      if(!random(5)) {
         SpeakStory();
         return;
      }
      else return 0;
   }
   else SpeakStory();
   return 0;
}

void SpeakStory() {
   string blah;
   blah = "What story to tell!  Let me think for a moment and I shall "
          "then begin.";
   switch(x) {
      case 1:
      switch(y) {
         case 0:
         blah = "Come, come, let me tell you a story!  Sit down, "
                "around yon fire, and listen close.";
         y++;
         break;
         case 1:
         blah = "I will tell today of the GodsWar.  You see, "
                "Duuktsaryth began sentient life on Kailie with "
                "his beloved elfs, and since then, many other "
                "races have sprung up.  Most hid during the "
                "war, like the muezzin, but some stayed out and "
                "fought, and many lives were lost.";
         y++;
         break;
         case 2:
         blah = "The Lady of the Oceans had lived in the Ruined "
                "Sea, but it did not have that name then.  Back "
                "then, at the beginning of the GodsWar, it was "
                "a beautiful, prosperous sea filled with the "
                "Merfolk.  Yes, those creatures are not mere "
                "fair tails, they existed!";
         y++;
         break;
         case 3:
         blah = "When the Lord of the Skies and the Lady of the "
                "Oceans were talking one day, they got into a "
                "dreadful dispute, and the Merfolk of the Oceans "
                "and the Dragons of the Sky attacked each other.";
         y++;
         break;
         case 4:
         blah = "Countless races died out during the following "
                "battles.  Only Duuktsaryth did not pull his "
                "children into hiding while remaining out of the "
                "battles.  Then the Ruined Sea gained its name.";
         y++;
         break;
         case 5:
         blah = "The Lord of the Skies attacked the Lady of the "
                "Oceans in her palace, and she was killed.  "
                "No Merfolk remain because of that battle, and "
                "the Ruined Sea will forever bear its deadly "
                "name as a reminder.";
         y++;
         break;
         case 6:
         blah = "Duuktsaryth came to end the madness that was "
                "destroying the continent.  His elves attacked "
                "Haven Town and emerged victorius.  A meeting "
                "was held by the Gods to determine the fate of "
                "Kailie.  Humans were created, allowed to freely "
                "choose what God to follow, and all the Gods were "
                "forced to remove themselves from everday life on "
                "Kailie.";
         y = 0;
         break;                
      }
      break;
      case 2:
      switch(y) {
         case 0:
         blah = "Gather near, gather near, I wish to try a riddle on "
                "you all!";
         y++;
         break;
         case 1:
         blah = "Three women were transformed into flowers which grew in "
                "a certain field.  There were no other flowers in "
                "this field, only grass and some brush, and all three "
                "flowers were identicle.";
         y++;
         break;
         case 2:
         blah = "One of these woman was granted a special gift due to "
                "goodness from past years.  She was allowed to transform "
                "back into a true woman at night, and return to her "
                "husband.  When day came, however, she had to return.";
         y++;
         break;
         case 3:
         blah = "Yet when cursed, the women had learned that one of them "
                "and only one had a chance for permanent freedom.  "
                "If a man could come and pick one of the flowers, she "
                "would be freed and the rest left for eternity in their "
                "cursed state.";
         y++;
         break;
         case 4:
         blah = "When the husband learned of this, he was determined to "
                "free his wife.  So one afternoon, he went to the field, "
                "and found the flower that was his wife.  So the question "
                "is, how did the husband know her, for these flowers were "
                "exactly alike, and without any different?";
         y++;
         break;
         case 5:
         blah = "Come now, think it, but speak not aloud, so others "
                "may have the chance!";
         y++;
         break;
         case 6:
         blah = "Well, I shall now have to tell you.  As the wife "
                "was at her home during the night and not in the "
                "field, no dew fell on her as it did on the others, "
                "and by this her husband knew her.  All ladies ought "
                "wish for so intelligent a husband.";
         y = 0;
         break;
      }
      break;
      case 3:
      switch(y) {
         case 0:
         blah = "Today is a fine day, is it not, to tell a story?  "
                "Come, let me tell you of the stolen nuggets of "
                "Farae, a foolish little dwarven girl who "
                "learned many things the hard way.  The story does not, "
                "however, begin with Farae, but with her parents a "
                "scant year beyond dear Farae's death.";
         y++;
         break;
         case 1:
         blah = "Farae's parents were kind people, and as they lived "
                "far from any inn or village, they often let strangers "
                "stay the night at their house.  One night, an old "
                "man who had seen much of the world came to visit, and "
                "he remained with the family until late that evening, "
                "telling tales of the things he had seen.";
         y++;
         break;
         case 2:
         blah = "At midnight, the storyteller had just finished another "
                "of his stories, and a peculiar apparation walked "
                "before him.  It was a white image, like that of a child, "
                "but pale and transluscent.  It walked to the back room "
                "of the house and then disappeared.";
         y++;
         break;
         case 3:
         blah = "The stranger asked the family of this child, and they "
                "professed no knowledge of it.  So the stranger remained, "
                "and sure enough, the child returned to the back room.  "
                "Only this time, the stranger followed.";
         y++;
         break;
         case 4:
         blah = "The child was bent down on her knees, digging "
                "furiously at the boards that her hands could not "
                "touch.  The storyteller told the family of this, and "
                "described the child, and the mother remembered poor "
                "Farae, their dead child.";
         y++;
         break;
         case 5:
         blah = "The stranger walked over to the spot the now-disappeared "
                "ghost had been poking at, and dug up part of the floor, "
                "only to find two nuggets sitting there!  The family "
                "wondered for a long while that night, trying to figure "
                "how Farae had known of these nuggets.";
         y++;
         break;
         case 6:
         blah = "Then the youngest child spoke up.  The darling remembered "
                "when both she and Farae had been given one nugget to "
                "give to a poor family if they chanced upon one.  "
                "Yet instead of obeying her parents, Farae took her "
                "nugget and the younger child's, burying them there in "
                "the back room.  Farae took ill soon after, but the "
                "youngest knew better than to speak up and face torment "
                "from her older sister.";
         y++;
         break;
         case 7:
         blah = "When Farae had died, the ghost continued to wander, "
                "remembering the nuggets hidden away that were meant to "
                "give a poor family.  The ghost ceased to return as "
                "soon as the nuggets were given away at their true "
                "purpose, and the entire family learned something new.";
         y = 0;
         break;
      }
      break;
   }
   eventForce("speak " + blah);
}
