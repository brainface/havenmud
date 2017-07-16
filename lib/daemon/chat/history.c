#include <lib.h>
#define HISTSIZE 400
inherit LIB_DAEMON;

mapping history = ([ ]);

static void create() {
  ::create();
  SetNoClean(1);
}

void AddHistory(string channel, string message) {
  if (!history[channel]) history[channel] = ({ });
  if (sizeof(history[channel]) >= HISTSIZE) history[channel] -= ({ history[channel][0] });
  history[channel] += ({ ({ time(), message }) });

}

mixed *GetHistory(string channel) {
  if (member_array(channel, this_player()->GetChannels()) == -1) return 0;
  return copy(history[channel]);
}
