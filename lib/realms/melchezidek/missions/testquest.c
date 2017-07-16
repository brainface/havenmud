#include <lib.h>

inherit LIB_MISSION;

int StageOnePartOne();
int StageOnePartTwo();
int StageOnePartThree();
int StageOnePartFour();
int StageTwo();
int StageTwoPartTwo();
int StageTwoPartThree();
int StageThree();
int StageThreePartTwo();
int StageThreePartThree();
int StageThreePartFour();
int StageFour();
int StageFive();
int StageFivePartTwo();
int StageSix();
int StageSixPartTwo();

static void create() {
  ::create();
  SetMissionName("Beornwulf Body Guard");
  SetTown("all");
  SetMissionDescription(
    "Ah, there you are. Seek out Lord Beornwulf, it seems he has need of some"
    " assistance concering some nasty letter he received or some such thing."
    );
  SetMissionLevel(60, 500);
  SetMissionPriority(90);
  SetReward("750000 XP");
}

int CheckCompletedMission(object who) {
    object *lord = ({});
    lord = filter(all_inventory(environment(who)), (: living($1) && $1->GetShort() == "Lord Beornwulf" :));
    
    if (base_name(environment(who)) == "/domains/southern_coast/areas/beornwulf_keep/room/warroom") {
         if (sizeof(lord) < 1) return 0;
          if (who->GetProperty("LordBQuestStage1") == 1) {
         call_out((: StageOnePartOne, who :), 0);
        }
         if (who->GetProperty("LordBQuestStage2") == 1) {
         call_out((: StageTwo, who :), 0);
        }
           if (who->GetProperty("LordBQuestStage3") == 1) {
           call_out((: StageThree, who :), 15);
          }
           if (who->GetProperty("LordBQuestStage4") == 1) {
           call_out((: StageFour, who :), 20);
          }
           if (who->GetProperty("LordBQuestStage5") == 1) {
           call_out((: StageFive, who :), 0);
          }
           if (who->GetProperty("LordBQuestStage6pt2") == 1) {
           call_out((: StageSixPartTwo, who :), 5);
          }
         if (who->GetProperty("LordBQuestFinished") == 1) {
          who->eventPrint("You have completed your tour of duty in Lord Beornwulf's service.");
          lord[0]->eventForce("speak Take care of yourself, and thanks for your hard work.");
          lord[0]->eventForce("speak and take this");
          who->AddCurrency("imperials", 25000);
          who->AddExperience(750000);
          who->RemoveProperty("LordBQuestFinished");
          return 1;
           }
     return 0;
   }
   return 0;
}

void AssignMission(object who) {
    who->SetProperty("LordBQuestStage1", 1);
}
int CanGetMission(object who) {
    return 1;
}



/* Stages of the Assault */



     /* Stage One - The Talk */


int StageOnePartOne(object who) {
  object *lord = ({ });
  lord = filter(all_inventory(environment(who)), (: living($1) && $1->GetShort() == "Lord Beornwulf" :));

lord[0]->eventForce("emote looks up from his paperwork.");
lord[0]->eventForce("speak Ah, there you are, " + who->GetCapName() + ". It is truely"
                 " a good thing you've arrived. I have received some messages concerning"
                 " a possible attack on my life.");
lord[0]->eventForce("emote shifts his weight.");
who->RemoveProperty("LordBQuestStage1");
who->SetProperty("LordBQuestStage1pt2", 1);
    call_out((: StageOnePartTwo, who :), 10);
   return 1;
}

int StageOnePartTwo(object who) {
object *lord = ({ });
    lord = filter(all_inventory(environment(who)), (: living($1) && $1->GetShort() == "Lord Beornwulf" :));

lord[0]->eventForce("speak Naturally, with the fighting outside, I do not give it much credence"
                    " but my advisors suggested having some extra muscle around just in case."
                    " That is where you come in.");
who->RemoveProperty("LordBQuestStage1pt2");                    
who->SetProperty("LordBQuestStage1pt3", 1);
call_out((: StageOnePartThree, who :), 10);
return 1;
  }

int StageOnePartThree(object who) {
  object *lord = ({ });
    lord = filter(all_inventory(environment(who)), (: living($1) && $1->GetShort() == "Lord Beornwulf" :));

lord[0]->eventForce("emote sighs.");
lord[0]->eventForce("speak So now you are here, we can get down to business. Your orders"
                    " are to stay by my side and act as a bodyguard, if you will.");
lord[0]->eventForce("emote claps his hands together.");
who->RemoveProperty("LordBQuestStage1pt3");
who->SetProperty("LordBQuestStage1pt4", 1);
call_out((: StageOnePartFour, who :), 8);
return 1;
}

int StageOnePartFour(object who) {
    object *lord = ({ });
    lord = filter(all_inventory(environment(who)), (: living($1) && $1->GetShort() == "Lord Beornwulf" :));

lord[0]->eventForce("speak So stand around and don't make a lot of noise, I've got a battle"
                    " to plan, and I despise when people make unnecessary noise.");
lord[0]->eventForce("emote returns his attention to his charts and maps.");
who->RemoveProperty("LordBQuestStage1pt4");
who->SetProperty("LordBQuestStage2", 1);
call_out((: StageTwo, who :), 30);
return 1;  
  }



    /* Stage Two - The Initial Attack */
    

int StageTwo(object who) {

message("shuffle", "A soft scuffle echoes throughout the room.", environment(who));
who->RemoveProperty("LordBQuestStage2");
who->SetProperty("LordBQuestStage2pt2", 1);
call_out((: StageTwoPartTwo, who :), 4);
return 1;
}

int StageTwoPartTwo(object who) {
    object *lord = ({ });
    object room = environment(who);
    lord = filter(all_inventory(environment(who)), (: living($1) && $1->GetShort() == "Lord Beornwulf" :));

lord[0]->eventForce("speak did you hear that, " + who->GetCapName() + "?");
lord[0]->eventForce("emote cocks his head to the side as if to hear better.");
who->RemoveProperty("LordBQuestStage2pt2");
who->SetProperty("LordBQuestStage2pt3", 1);
call_out((: StageTwoPartThree, who :), 10);
return 1;
}

int StageTwoPartThree(object who) {
    object *lord = ({ });
    object room = environment(who);
    object assassin;
    lord = filter(all_inventory(environment(who)), (: living($1) && $1->GetShort() == "Lord Beornwulf" :));
assassin = new("/std/npc/assassin1");
lord[0]->eventForce("speak I could of sworn I hea....");
assassin->eventMove(room);
lord[0]->eventForce("speak Assassins! I don't believe it. To arms, " + who->GetCapName() + "! Do"
                        " your bloody job!");
    who->eventForce("attack assassin");

return 1;
}


  /* Stage 3 - The Pause and Realization */
  
  
int StageThree(object who) {
    object *lord = ({ });
    lord = filter(all_inventory(environment(who)), (: living($1) && $1->GetShort() == "Lord Beornwulf" :));

lord[0]->eventForce("emote checks himself over for wounds.");
lord[0]->eventForce("speak how did you fare, " + who->GetCapName() + "? Never mind that, I'm"
                    " sure you're fine.");
who->RemoveProperty("LordBQuestStage3");
who->SetProperty("LordBQuestStage3pt2");
call_out((: StageThreePartTwo, who :), 10);
return 1;
}

int StageThreePartTwo(object who) {
  object *lord = ({ });
    lord = filter(all_inventory(environment(who)), (: living($1) && $1->GetShort() == "Lord Beornwulf" :));
    
    lord[0]->eventForce("emote crouches over the corpse of the assassin to investigate it.");
    call_out((: StageThreePartThree, who :), 7); 
    return 1;
  }
int StageThreePartThree(object who) {
  object *lord = ({ });
    lord = filter(all_inventory(environment(who)), (: living($1) && $1->GetShort() == "Lord Beornwulf" :));

lord[0]->eventForce("emote hmms.");
lord[0]->eventForce("speak it seems this assassin is from the Order of the Wolf... hmm");
call_out((: StageThreePartFour, who :), 7);
 return 1;
}

int StageThreePartFour(object who) {
  object *lord = ({ });
    lord = filter(all_inventory(environment(who)), (: living($1) && $1->GetShort() == "Lord Beornwulf" :));

lord[0]->eventForce("The Order of the Wolf is known for their perserverance. I do not think"
                    " this will be a quiet evening, " + who->GetCapName() + ". Prepare yourself"
                    " for the worst.");
lord[0]->eventForce("emote begins to sharpen his sword.");
who->RemoveProperty("LordBQuestStage3");
who->SetProperty("LordBQuestStage4", 1);
 return 1;
}


  /* Stage Four - Second Attack */
  
  
int StageFour(object who) {
  object *lord = ({ });
    object room = environment(who);
    object assassin;
    lord = filter(all_inventory(environment(who)), (: living($1) && $1->GetShort() == "Lord Beornwulf" :));
assassin = new("/std/npc/assassin2");
message("shuffle", "A soft scuffle echoes throughout the room.", environment(who));
lord[0]->eventForce("speak Here we go, get ready, they could come from anywhere, very sneaky"
                    " these guys are.");
assassin->eventMove(room);
who->RemoveProperty("LordBQuestStage4");
who->SetProperty("LordBQuestStage4pt2", 1);
return 1;
}


     /* Stage 5 - The Final Pause */
     

int StageFive(object who) {
object *lord = ({ });
    lord = filter(all_inventory(environment(who)), (: living($1) && $1->GetShort() == "Lord Beornwulf" :));

lord[0]->eventForce("emote takes a deep breath.");
lord[0]->eventForce("speak I told you they were relentless. I'm sure this is not over yet.");
lord[0]->eventForce("speak Keep your wits about you, heal as you like, just do not let your"
                    " guard down, " + who->GetCapName() + ".");
who->RemoveProperty("LordBQuestStage5");
who->SetProperty("LordBQuestStage5pt2", 1);                    
call_out((: StageFivePartTwo, who :), 10);
  return 1;
}

int StageFivePartTwo(object who) {
object *lord = ({ });
    lord = filter(all_inventory(environment(who)), (: living($1) && $1->GetShort() == "Lord Beornwulf" :));

message("shuffle", "A soft scuffle echoes throughout the room.", environment(who));
lord[0]->eventForce("speak Ah, no rest for us it seems. Prepare to die, Assassins!");
who->RemoveProperty("LordBQuestStage5pt2");
who->SetProperty("LordBQuestStage6", 1);
 return 1;
}

    
      /* Stage Six - The Final Attack and Resolution */
      
    
int StageSix(object who) {
  object *lord = ({ });
    object room = environment(who);
    object assassin;
    lord = filter(all_inventory(environment(who)), (: living($1) && $1->GetShort() == "Lord Beornwulf" :));
assassin = new("/std/npc/assassin4");
assassin->eventMove(room);
who->RemoveProperty("LordBQuestStage6");
who->SetProperty("LordBQuestStage6pt1", 1);
return 1;
}

int StageSixPartTwo(object who) {
  object *lord = ({ });
    lord = filter(all_inventory(environment(who)), (: living($1) && $1->GetShort() == "Lord Beornwulf" :));

lord[0]->eventForce("speak Good work, " + who->GetCapName() + ". I'm not sure I would of"
                    " made it out if you had not been around.");
lord[0]->eventForce("speak But, it seems as if this problem is going to be more long term."
                    " As such, perhaps it is for the best if I hire a full time body guard.");
  who->SetProperty("LordBQuestFinished", 1);

return 1;
}

