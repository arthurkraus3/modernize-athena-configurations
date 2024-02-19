# modernize-athena-configurations
Work on bringing Athena configurations up to speed with xAOD format and component accumulator

#### The goal
is to look at the tests written by Peter Van Gemmeren, take inventory first of what's going on in the tests, and figure out what technologies aren’t being used anymore to get an idea of what’s there and then get an idea of what we can/should change first. There's a lot more tests out there but the two included in the `initial-testing` directory will be a fine start for now. 

Running the following commands will get you to run the `initial-testing`
```
lsetup "asetup Athena,main,latest"; 
athena AthenaPoolExampleAlgorithms/AthenaPoolExample_WriteJobOptions.py >> writelog.txt;
athena AthenaPoolExampleAlgorithms/AthenaPoolExample_ReadJobOptions.py >> readlog.txt;
```

And will result in the following files

```
total 388
-rw-r--r--. 1 akraus zp    667 Feb 19 20:24 Catalog1.xml
-rw-r--r--. 1 akraus zp  29173 Feb 19 20:24 EmptyPoolFile.root
-rw-r--r--. 1 akraus zp  39772 Feb 19 20:24 SimplePoolFile1.root
-rw-r--r--. 1 akraus zp  36213 Feb 19 20:24 SimplePoolFile2.root
-rw-r--r--. 1 akraus zp     66 Feb 19 20:25 eventLoopHeartBeat.txt
-rw-r--r--. 1 akraus zp 149529 Feb 19 20:25 readlog.txt
-rw-r--r--. 1 akraus zp 123313 Feb 19 20:24 writelog.txt
```

I won't include ROOT files, but I'll include the (read/write)log.txt in the `initial-testing` directory. 
