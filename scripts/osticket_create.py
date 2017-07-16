import requests
import json
from os import listdir, makedirs, rename, walk
from os.path import isfile, join, exists
import logging

key='4D7F490550FA8A95A163F8D92EFEEF5F'
#host='osticket.creepyneighbor.net'
host = 'bugs.havenmud.com'
protocol='https'
uri='api/http.php/tickets.json'
url='%s://%s/%s' % (protocol, host, uri)

bug_dir = '/home/haven/haven/lib/log/bugs'
processed_dir = '%s/processed' % bug_dir

logger = logging.getLogger('osticket')
#logger.setLevel(logging.DEBUG)
logger.setLevel(logging.INFO)
fh = logging.FileHandler("os_ticket_import.log")
formatter = logging.Formatter('%(levelname)s [%(asctime)s] - %(message)s')
fh.setFormatter(formatter)
logger.addHandler(fh)

def create_ticket(bug):
	if bug is None:
		return
	headers = {'X-Api-Key': key,
		   'Content-Type': 'application/json'}
	
	data = {
		'name'   : bug['requestor'],
		'email'  : bug['requestor_email'],
		'subject': bug['subject'],
		'message': bug['full_text'],
		'ip'     : '23.253.225.109',
		'topicId': bug['type']
		} #phone: bleh removed
	try:
		r = requests.post(url, headers=headers, data=json.dumps(data))
		pass
	except Exception as e:
		logger.error("Could not submit ticket for %s! Exception: %s" % (bug['id'], e))
		return False
	logger.info("Created osTicket [%s] for bug [%s]" % (r.text, bug['id']))
	return True

def get_bugs():
	bugs = [join(bug_dir,f) for f in listdir(bug_dir) if isfile(join(bug_dir, f))
			and f.endswith('.bug')]
	#bugs = []  # this is all for the 'mass import' leaving it for now incase we need to do that again
	#for root, dirs, files in walk(bug_dir):
	#	for name in files:
	#		if name.startswith('.'):
	#			pass
	#		else:
	#			bugs.append(join(root, name))
	logger.debug("Found %s bug reports for processing in %s." % (len(bugs), bug_dir))
	return bugs


def parse_bug_report(bug, bug_dir='/home/haven/haven/lib/log/bugs'):
	b = {}
	b['full_text'] = []
	bug_file = bug
	try:
		bug = bug.split('/')[-1]
	except:
		bug = bug
		logger.error("Bug didn't have full path: %s" % bug)
	logger.debug("Parsing bug report: %s" % join(bug_dir, bug))
	with open(bug_file, 'r') as f:
		try:
			b['id'] = bug.split('.')[0]
		except:
			logger.error("Malformed bug id: %s" % bug)
			b['id'] = bug[0:25]
                b['type'] = None
                b['requestor'] = None
                b['requestor_email'] = None
                b['requested_at'] = None
                b['subject'] = None
		for line in f:
			b['full_text'].append(line)
			if line.startswith('Reported by'):
				s = (line.split(':')[1].lstrip()).split(' ')
				
				b['requestor'] = s[0]
				b['requestor_email'] = s[1].replace('(', '').replace(')','').strip()
			if line.startswith('Time'):
				b['requested_at'] = line.split(':')[1].lstrip()
			if line.startswith('Type'):
				type = line.split(':')[1].strip()
				if type == 'runtime':
					b['type'] = 12
				elif type == 'idea':
					b['type'] = 1
				elif type == 'typo':
					b['type'] = 2
				elif type == 'quest idea':
					b['type'] = 10
				elif type in ['unexplained behaviour', 'unexplained behavior']:
					b['type'] = 11
				else:
					b['type'] = 13 # uncategorized
			if line.startswith('Bug'):
					b['subject'] = '%s - %s' % (b['id'], line.split(':')[1].lstrip()[0:35])
	b['full_text'] = ''.join(b['full_text'])
	if b['type'] is None or b['requestor'] is None or b['requestor_email'] is None:
		logger.error("Failed to parse bug: %s" % bug_file)
		return None
	logger.debug("Finished parsing %s: type [%s] from [%s (%s)]" % 
			(bug, b['type'], b['requestor'], b['requestor_email']))
	return b


if __name__ == "__main__":
	if not exists(processed_dir):
		logger.info("Created processed dir: %s)" % processed_dir)
		makedirs(processed_dir)
	for bug in get_bugs():
		try:
			resp = create_ticket(parse_bug_report(bug))
		except Exception as e:
			resp = None
			logger.error("Failed to process file %s: (%s)" % (bug, e))
		if resp:
			# move file
			bug_base = bug.split('/')[-1]
			rename(bug, join(processed_dir, bug_base))
			logger.debug("Moved %s from [%s] to [%s]" % (bug_base, bug, '%s/%s' % (processed_dir, bug_base)))
