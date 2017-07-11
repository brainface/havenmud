#include <lib.h>
#include "../haven.h"
inherit LIB_NPC;

int requestTour(object who, string what);
int eventTour(object *who, int iter);

string *Tour = ({
        "speak Welcome to Haven Town. I'll be happy to show you around.",
        "tourooc Please, don't use your keyboard while you follow the tour "
              "guide. You can use <look> to see the room again if you like.",
        "speak This is the Elven Aide Charity, a very helpful building for "
              "young citizens of Haven Town. Loran, the Aider of the Youth, "
              "will assist all citizens of Haven Town with a few items they "
              "may find useful just <request> them from her. Also up above "
              "is a place where one can sleep peacefully.",
        "go out",
        "speak This is Merchant's Way and most stores and shop can be found "
              "on this stretch of road. You can <enter store> to find out what "
              "Taylor is selling today. Also Taylor is known for selling "
              "torches.",
        "tourooc I recommend the following help files: <help vendors>, "
              "<help levels>, and <help mortal>.",
        "go west",
        "speak Continuing down Merchant's Way, we find another shop called "
              "Fidget's Armoury. Fidget is a different kind of vendor than "
              "Taylor. Fidget always has something to sell, but will not buy "
              "anything.",
        "go west",
        "speak This is the end of the Merchant quarter. Now we head to the heart "
              "of Haven Town where the Church of Kylin is located.", 
        "go north",
        "speak Here along the side of the road is the town hall where our fine mayor "
              "resides. You can <enter hall> to seek an audience with the mayor at "
              "any time.",
        "enter hall",
        "speak This is the Town Hall, the central governmental building in town. "


              "Here, people can come and request citizenship into our great "
              "town from Annax. There is a news board here, which keeps our citizens "
              "update with the happenings of town and wanted poster for those who "
              "have committed crimes against our citizens. ",
        "speak It might be a good idea to check up on the news board (\"help "
              "news\") once in a while.",
  "go up",
  "speak Here is the lovely Astara, wife to Annax. She passes her days "
        "by teaching elves and humans the languages of other towns. "
        "Astara would recommend you learn other languages and <help "
        "languages>.",
  "go down",
  "go out",
  "go north",
  "go north",
  "speak This is the center of Haven Town, but not the heart of it. Here "
        "you may <drink from fountain> if you are thirsty. Usually there is "
        "a dwarven merchant looking to hire a strong and able guard to protect "
        "her on the journey homeward. You may <ask dwarf for job> if you "
        "think you can defend her from bandits.",
  "go west",
  "speak Further west of here is the town gate and where our templars defend "
        "us from invasions. But here and I must warn you, only those legendary "
        "souls may enter this evil grove (\"help levels\").",
  "go east",
  "go north",
  "speak Here along the Holy Path is a temple for those tree-hugging Eclats. "
        "I think Annax lost his mind for allowing the Eclat to build this "
        "temple so close to our most holy Church of Kylin. You can <enter "
        "temple> and speak with the druids that reside there.",
  "go north",
  "go north",
  "speak Here lies the Church of Kylin, the heart of Haven Town. "
      "Lying to our west is the Haven Town cemetery. A quiet place, "
      "this is where you will appear should you ever die (\"help death\") "
      "while walking Kailie. Should you find yourself undead, it is best "
      "if you <enter church> and seek the healers help. You may <enter "

      "cemetery> and explore the cemetery if you strong enough to battle "
      "the ghouls and skeletons, which inhabit that hallowed ground. "
      "Using <help areas> will let you know if you are brave or foolish "
      "enough to do battle there.", 
  "enter church",
  "speak Welcome to the Temple of Kylin. This is the most important "
      "building for the Faithful. To the north, you can find the town "
      "healer Quelthon. The healer can perform many actions for you, "
      "including restoring lost limbs, healing damage, and even "
      "resurrecting you should you die.",
  "go east",
  "speak This is the Sanctuary of Kylin where Dalahalus, the High Priest "
      "of Kylin, normally can be found praying and preaching to the "
      "Faithful. If you wanted, you could <ask dalahalus to join cleric> "
      "to begin your path on a career of pious learning. ",
  "speak Once you did that, you would also need to <ask dalahalus to "
      "teach> the various spells. (You can find those spells in \"help "
      "allspells\" and compare that list to your new skills.)",
  "speak To the north is a room, which is protected by the mighty "
      "Duuk, the Lord of Balance and Supreme Deity of Kailie. Only "
      "the Faithful of Kylin may seek refuge there.",
  "go west",
  "go out",
  "speak One thing I forgot to mention, there was an elf named Caranthir "
      "he was an Archduke of Haven Town and Paladin of Kylin. Duuk "
      "rid him for crimes too heinous to mention (\"help pk\").",
  "go south",
  "go south",
  "enter temple",
  "speak I did not mention this last time and I am already cringing, as I am "
      "about to say this. If you wanted to become a druid of Eclat, you can "
      "<convert> (\"help convert\") to Eclat by <ask suvraela to convert me>. "
      "Once you are an Eclat you can <ask suvraela to join druid>. Suvraela "
     "can also teach you spells if you are an Eclat druid. ",
  "go out",
  "go south",
  "go east",

  "go east",
  "speak From here, you can <enter> two very important buildings. The first "
      "is the Haven Bank, where you will be able to exchange all the foreign "
      "coins you find into shiny imperials. You'll also be able to save your "
      "money there, which is very good in case you should happen to die. (For "
      "more information, you should <help banking>.)",
  "speak The second building is an inn called Ruperts Hole. This three-story "
        "building, is where you can <ask rupert to sell stew> which is filling "
        "if you are hungry. There is a quiet and peaceful room on the second "
        "floor for warriors to rest. The upper floor is the home of Timmy "
        "Longdorf, a retired merchant and you can <ask timmy to join merchant> "
        "if you wish to pursue that career.",
  "go east",
  "speak North of this stretch of road is the Hall of Musicians. Where you could "
        "begin a career as a Bard. Let us continue the tour. ",
  "go east",
  "speak Here is the post office for Haven Town.",
  "enter office",
        "speak In here, you can send and receive mail from other people on Kailie. You "
              "can also read the news board, which includes important announcements from "
              "the Immortals and an Out-Of-Character discussion. To read the news, simply "
              "use <news>.",
 "go out",
 "go east", 
 "speak At this intersection of Imperial Road and Galleon's Passage, if you headed "
       "north you would find a sacred grove and the town barracks. Heading eastward "
       "would bring you to the Great Library of Haven and heading southward leads "
       "you to the Haven Town wharf.",
 "go north",
 "go north",
 "go north",
 "speak The Haven Town Guard resides and trains inside the barracks. If you are "
       "looking to pursue a combat-oriented life in Haven Town as a guard seek "
       "out Damon and <ask damon to join fighter>. If you have a strong sense "
       "of honor, the strength to uphold justice, and you which to join the "
       "ranks of knighthood; <ask nastarum to join cavalier>.",
 "go north",

 "speak Welcome to the holy grove where a few of our elves still practice the "
       "Old Ways. Istil, Master Ranger, is normally here waiting to recruit "
       "any who which to pursue the lonely life as a ranger. Raunthala, is "
       "a practitioner of the Old Ways, if you are pure in your faith to the "
       "Old Ways <ask raunthala to join druid>.",
 "go south",
 "go south",
 "speak Tired already? There is more to see.",
 "go south",
 "go south",
 "go east",
 "speak We are standing outside the Grand Library of Haven Town. I would "
      "take you inside but I have been asked nicely never to return. If "
      "you are interested in wielding great magical power, you may join "
      "the ranks of enchanter, evoker or even the dreaded necromancer. "
      "The life of a mage is moderately difficult but the rewards of "
      "power are worth it.",
 "tourooc For more help use <help evoker>, <help enchanter>, and "
      "<help necromancer>.)",
 "go west",
 "go south",
 "go south",
 "speak As you explore the world outside Haven Town, you will find yourself "
      "not able to carry everything you find. If you have enough money, you "
      "should invest in buying a mule from Alpacha's Stable which is accessed "
      "by <enter stable>. A mule will carry your belongings to allow you to "
      "save your strength for the combat.",
 "go south",
 "speak This is a busy intersection as the captains of ships try to "
            "unload their cargo to the merchants of Haven Town. At this "
            "intersection of Merchant's Way and Galleon's Passage is a massive "
            "warehouse which you could <enter> if you wanted. ",
 "enter warehouse",
 "speak This massive building is where the Elven Navy is built. For "
            "those young citizens interested in sailing the high seas should "
            "<ask Padagon to join sailor>. If you already have another "
            "career path and still want to sail the high seas <ask "

            "tanislantha to train> you in those skills you require, like "
            "sailing, swimming and navigation.",
 "speak Aruthan can <sell> you ship if you are brave enough to venture "
      "on the high seas and if you have enough money to buy one. ",
 "go out",
 "go south",
 "speak Here lies the Port of Haven Town. Normally you will be able "
            "to find Talis here fishing and he is willing to teach citizens "
            "of Haven Town how to fish. Another building of note in our "
            "fair town is the tavern, Divine Chalice. ",
 "speak It is rumored that there is a rogue that is operating out of that "
      "tavern. If one wants to become a vile and sneaky thief you need to "
      "<ask targeryan to join rogue>. That tavern has been closed down "
      "before for such activities.",
 "go north",
 "go west",
 "speak Almost done. Just a few more steps and the tour will be finished.",
 "go west",
 "speak We find another shop along Merchant's Way called Naythen's Smithy. "
      "I hear Naythen is a little bit more reasonable than Taylor, but he only "
      "buys and sells weapons. ",
 "go west",
 "enter charity",
 "speak Last but not least, Hustin is looking for a few brave souls to take up "
      "a quest, so just <ask hustin for quest>.",
        "speak Thank you for taking my tour!",
        });
object *Tourists = ({ });
int TourCount = 0;

static void create() {
  ::create();
  SetKeyName("Elor");
  SetId( ({ "elor", "guide" }) );
  SetAdjectives( ({ "tour", "haven", "elor" }) );
  SetShort("Elor the Haven Town guide");
  SetLong(
    "This tall green haired almond skinned elf is Elor. He has been "
    "appointed by Annax Banewulf to show young citizen around town "
    "to learn everything about Haven Town."
    );
  SetRace("elf");
  SetClass("merchant");
  SetLevel(35);
  SetMorality(100);
  SetTown("Haven");
  SetGender("male");
  SetCurrency("imperials", random(20)+1);
  SetAction(15, ({
        "!speak If you'd like, you can <request tour from tour guide>",
        "!speak I'd be happy to show you around town.",
        "!speak Let me show you around town.",
        "!speak Welcome to Haven!",
    }) );
  AddChannel( ({ "tourooc" }) );
  AddRequestResponse("tour", (: requestTour :) );
  SetLimit(1);
  set_heart_beat(5);
}

void heart_beat() {
        ::heart_beat();
        if (sizeof(Tourists))
          eventTour(Tourists, TourCount);
}

mixed eventAsk(object who, string what) {
        mixed t = ::eventAsk(who, what);
        eventForce("speak If you'd like me to take you on a tour, please just "
                   "<ask guide for tour>.");
        return t;
}

mixed eventRequest(object who, string what) {

        mixed t = ::eventRequest(who, what);
        if (what != "tour") {
                eventForce("speak If you'd like me to take you on a tour, please "
                           "just <ask guide for tour>!");
                           }
        return t;
}

int requestTour(object who, string what) {
        if (what != "tour") {
                eventForce("speak Did you want a tour? If so, <request tour from tour guide>");
                return 1;
        }
        eventForce("speak Wonderful!  I'll show you around!");
        who->eventForce("follow tour guide");
        eventForce("lead " + who->GetKeyName());
        Tourists += ({ who });
        who->AddChannel( ({ "tourooc" }) );
        SetAction(0, ({ }) );
        set_heart_beat(12);
        return 1;
}

int eventTour(object *who, int num) {
        if (num < sizeof(Tour)) {
         eventForce(Tour[num]);
          TourCount++;
        }
        if (TourCount == sizeof(Tour)) {
                eventForce("wave");
                foreach(object tourist in Tourists) {
                        if (!tourist) continue;
                        if (environment() != environment(tourist)) continue;
                        if (!(tourist->GetQuestCompleted("Haven Tour"))) {
                          tourist->AddQuest("the Haven Tourist", "Haven Tour");
                          tourist->AddDevelopmentPoints(2);
                          tourist->RemoveChannel( ({ "tourooc" }) );
                          set_heart_beat(5);

                          }
                        }
                Tourists = ({ });
                TourCount = 0;
                SetAction(90, ({
          "!speak If you'd like, you can <request tour from tour guide>",
          "!speak I'd be happy to show you around town.",
          "!speak Haven Town is a large town, let me show you.",
          "!speak Welcome to Haven Town!",
      }) );
                }
        return TourCount;
}
