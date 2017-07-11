/*   Portia@Haven
     2-8-99
     The object to initiate the test to see if a
     player is cool enough to be an angel.
 */

#include <lib.h>
#include <daemons.h>
#define WHO environment()
inherit LIB_ITEM;
#include <angel_questions.h>

int eventStartTest();
void angel_file(object who, string what);
void eventQuestion(string);
int i;

static void create() {
  ::create();
  SetKeyName("angel_test_obj");
  SetShort("an angel test object");
  SetInvis(1);
  SetPreventGet(1);
  SetPreventDrop(1);
}

void angel_file(object who, string what) {
  write_file("/log/secure/tests/" + WHO->GetKeyName(),
    what + "\n");
  }

int eventStartTest() {
  if ( file_exists("/log/secure/tests/" + WHO->GetKeyName() ) ) {
    WHO->eventPrint("%^MAGENTA%^You have already taken the test. \n"
                    "Please be patient an Arch will contact \n"
                    "you shortly.%^RESET%^");
    return 1;
  }
  i = 0;
  WHO->eventPrint("%^BLUE%^BOLD%^Please remember that these are short answer \n"
    "questions. Please refrain from hitting <enter> until you \n"
    "have answered the question fully. Essay questions must be \n"
    "kept to three sentences as longer answers will not register. \n"
    "Typing 'quit' for any answer will terminate your test. \n"
    "Thank You and Good Luck!%^RESET%^");
  WHO->eventPrint("%^MAGENTA%^" + Questions[i] + "%^RESET%^");
  angel_file(WHO, Questions[i]);
  input_to( (: eventQuestion :) );
  return 1;
}

void eventQuestion(string answer) {
  if (answer == "quit") {
    eventDestruct();
    return;
  }
  angel_file(WHO, answer);
  i++;
  if ( i > (sizeof(Questions) -1 ) ) {
   WHO->eventPrint("%^YELLOW%^Thank you, your test will be reviewed "
                   "by the Muses and Arches.  You will have an answer "
                   "within three days.%^RESET%^");
    CHAT_D->eventSendChannel("Test", "reports", WHO->GetCapName() + " submitted an Angeltest.");
    eventDestruct();
    return;
    }
  WHO->eventPrint("%^MAGENTA%^" + Questions[i] + "%^RESET%^");
  angel_file(WHO, "\n");
  angel_file(WHO, Questions[i]);
  input_to( (: eventQuestion :) );
}


