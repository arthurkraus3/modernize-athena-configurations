# modernize-athena-configurations
Work on bringing Athena configurations up to speed with xAOD format and component accumulator

### myAthena
Athena testing can be difficult to get started with. I tried to make it as simple as possible, for myself at least, to streamline the process no matter where you are in the CERN compute ecosystem. (I'm still updating it, so hopefully it'll be even easier over time)

[myAthena](https://github.com/arthurkraus3/myAthena) is the repo to initialize, modify, and source your own local version of Athena.  


### The initial goal
was to look at the tests written by Peter Van Gemmeren, take inventory first of what's going on in the tests, and figure out what technologies aren’t being used anymore to get an idea of what’s there and then get an idea of what we can/should change first. There's a lot more tests out there but the two included in the `initial-testing` directory will be a fine start for now. 

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

### Update 24.2.28:
Create a new algorithm first by running 
```
acmd gen-klass --klass MyTestAlgorithm --type reentrant_alg --pkg MyTestPackage --output-file MyTestAlgorithm
```
which will create two files in the current dir, a source and header file. They hold a template for `AthReentrantAlgorithm`. `--klass` controls the name of the algo, `--pkg` controls the name of the package (info used in the header file), and `--output-file` controls the name of the `.cxx` and `.h` files. More info with
```
acmd gen-klass --help
```
Thanks to Serhan Mete for this tip. 

### Update 24.3.18:
It must be a part of the athena framework in order to work properly, just running
```
python3 AthenaPoolExample_WriteJobOptions.py
```
will not work. 
