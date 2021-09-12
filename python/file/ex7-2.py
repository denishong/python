import os
def print_flist(path):
	f=open('flist.txt', 'wt')
	flist=os.listdir(path)
	for x in flist:
		f.write('%s\n' % x)
	f.close()
