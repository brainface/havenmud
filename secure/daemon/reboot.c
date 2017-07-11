#include <lib.h>
#include <daemons.h>
inherit LIB_DAEMON;

int REBOOT_INTERVAL = 60 * 24;
int LastAnnouncement, HardReboot, SkipBackup;
static void eventReboot();
void eventAnnounce();
int GetNextReboot();
int GetNextAnnouncement();
int SetNextReboot(int, int);

static void create() {
  ::create();
  SetNoClean(1);
  LastAnnouncement = 0;
  HardReboot = 0;
  SkipBackup = 0;
  set_heart_beat(1);
}

void heart_beat() {
  eventAnnounce();
  if (memory_info() > 100000000 && !HardReboot) {
    CHAT_D->eventSendChannel("Memory/Lag Reboot", "reboot", "Initiating lag/memory warning reboot automatically.");
    log_file("reports/reboot", "Memory reboot initiated at " + ctime(time()) + "\n" );
    SetNextReboot(15, 0);
  }
}
      
static void eventReboot() {
   message("broadcast",
     "%^BOLD%^YELLOW%^" +
     "A cheerful voice whispers to you, \"%^RESET%^BLUE%^Don't Panic.%^RESET%^BOLD%^YELLOW%^\"%^RESET%^", users() );
   map(users(), (: catch($1->cmdQuit("master")) :));
   if (SkipBackup) { shutdown(12); } else { shutdown(); } 
}

void eventAnnounce() {
  int days, hours, minutes, seconds;
  string msg = "";
  string *units = ({ });
  int nextreboot = GetNextReboot();
  int announce = GetNextAnnouncement();

  days    = nextreboot / 86400;
    
  hours   = (nextreboot - (days * 86400)) / 3600;
  minutes = ((nextreboot - (days * 86400)) % 3600 ) / 60;
  seconds = nextreboot - (days * 86400) - (hours * 3600) - (minutes * 60);
  if (nextreboot > 150) msg = "%^RESET%^MAGENTA%^"; else msg = "%^BOLD%^YELLOW%^";
  if (days)    units += ({ consolidate(days, "one day") });
  if (hours)   units += ({ consolidate(hours, "one hour") });
  if (minutes) units += ({ consolidate(minutes, "one minute") });
  if (seconds) units += ({ consolidate(seconds, "one second") });
  msg += capitalize(conjunction(units, "and"));
  msg += " until reboot and falling.%^RESET%^";
  if (nextreboot <= 0) { eventReboot();  log_file("reboot", "Reboot completed at " + ctime(time())); CHAT_D->eventSendChannel("Negative Reboot Time!", "error", nextreboot); return; }
  if (announce < time()) {
    CHAT_D->eventSendChannel("", "reboot", msg, 1);
	  LastAnnouncement = time();
	  }
}

int GetNextReboot() {
  int n = (REBOOT_INTERVAL * 3600) - uptime();
  if (HardReboot) return HardReboot - time();
  return n;
}

varargs int SetNextReboot(int minutes, int nobackup) {
  HardReboot = time() + (minutes * 60);
  SkipBackup = nobackup;
  return HardReboot;
}

int SetLastAnnouncement(int x) { return LastAnnouncement = x; }
int GetLastAnnouncement()      { return LastAnnouncement; }

int SetSkipBackup(int x) { return SkipBackup = x; }
int GetSkipBackup()      { return SkipBackup;     }

int GetNextAnnouncement()  {
  int announce;
  int nextreboot = GetNextReboot();
  
                          announce = LastAnnouncement + 10;    /* Less than 2 minutes */
  if (nextreboot > 120 )  announce = LastAnnouncement + 30;    /* > 2, less than 5 min*/
  if (nextreboot > 300 )  announce = LastAnnouncement + 60;    /* > 5 less than 10 min*/
  if (nextreboot > 600 )  announce = LastAnnouncement + 300;   /* > 10 < 30 min       */
  if (nextreboot > 1800)  announce = LastAnnouncement + 600;   /* > 30 < 60 min       */
  if (nextreboot > 3600)  announce = LastAnnouncement + 1200;  /* > 1 hr < 2 hr       */
  if (nextreboot > 7200)  announce = LastAnnouncement + 3600;  /* > 2 hr < 4 hr       */
  if (nextreboot > 14400) announce = LastAnnouncement + 7200;  /* > 4 hr < 8 hr       */
  if (nextreboot > 28800) announce = LastAnnouncement + 14400; /* > 8 hr < 24 hr      */
  if (nextreboot > 86400) announce = LastAnnouncement + 28800; /* > 24 hr             */
  return announce;
}

int GetRebootInterval()      { return REBOOT_INTERVAL; }
int SetRebootInterval(int x) { return REBOOT_INTERVAL = x; }

varargs void eventRebootMud(int x, int y) {
  CHAT_D->eventSendChannel("REBOOT_D", "imm", "Master Daemon attempted to use eventRebootMud");
}

void eventForceAnnounce() {
  int days, hours, minutes, seconds;
  string msg = "";
  string *units = ({ });
  int nextreboot = GetNextReboot();
  int announce = GetNextAnnouncement();

  days    = nextreboot / 86400;
    
  hours   = (nextreboot - (days * 86400)) / 3600;
  minutes = ((nextreboot - (days * 86400)) % 3600 ) / 60;
  seconds = nextreboot - (days * 86400) - (hours * 3600) - (minutes * 60);
  if (nextreboot > 150) msg = "%^RESET%^MAGENTA%^"; else msg = "%^BOLD%^YELLOW%^";
  if (days)    units += ({ consolidate(days, "one day") });
  if (hours)   units += ({ consolidate(hours, "one hour") });
  if (minutes) units += ({ consolidate(minutes, "one minute") });
  if (seconds) units += ({ consolidate(seconds, "one second") });
  msg += capitalize(conjunction(units, "and"));
  msg += " until reboot and falling.%^RESET%^";
  CHAT_D->eventSendChannel("", "reboot", msg, 1);
}
