/*  A voting booth */
#include <lib.h>
#include <save.h>
inherit LIB_ITEM;
mixed direct_vote_with_obj_for_str(string str);
int eventVote(object who, string vote);
string SetBoothId(string);
string GetBoothId();
mapping Votes = ([ ]);
string BoothId = "lib";

static void create() {
  item::create();
  restore_object(SAVE_VOTES + GetBoothId() );
  AddSave( ({ "Votes" }) );
  SetPreventGet("You cannot take the voting booth!");
  }

mixed direct_vote_with_obj_for_str(string str) {
  return 1;
 }

int eventVote(object who, string vote) {
  Votes[who->GetKeyName()] = vote;
  message("system", "You vote " + vote + ".", who);
  save_object(SAVE_VOTES + "/" + GetBoothId() );
  return 1;
 }

string SetBoothId(string str) {
  return BoothId = str;
 }

string GetBoothId() {
  return BoothId;
 }

void eventReportVotes() {
  mapping Returns = ([ ]);
  foreach(string person, string vote in Votes) {
    if (!Returns[vote]) Returns[vote] = 1;
    else Returns[vote]++;
   }
  foreach(string vote in keys(Returns)) {
    this_player()->eventPrint(vote + " : " + Returns[vote]);
   }
 }
