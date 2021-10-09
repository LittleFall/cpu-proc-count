# cpu-proc-count

count how many threads are running by each cpu.

```
g++ cpc.cpp -o cpc 
watch -n 0.2 ./cpc [proc_name]
```

## TODO

1. set `cores` as a client parameter.
2. export result to prometheus

## example

```shell
Every 0.2s: ./cpc tiflash                                                                                                                 Sat Oct  9 18:01:42 2021

will execute: ps -eLo "psr stat pid lwp cmd" | grep tiflash
total 6609 threads
cpu  0: runnable:3    interruptible:154   uninterruptible:0    total:157
cpu  1: runnable:2    interruptible:170   uninterruptible:0    total:172
cpu  2: runnable:0    interruptible:183   uninterruptible:0    total:183
cpu  3: runnable:0    interruptible:164   uninterruptible:0    total:164
cpu  4: runnable:3    interruptible:169   uninterruptible:0    total:172
cpu  5: runnable:1    interruptible:165   uninterruptible:0    total:166
cpu  6: runnable:1    interruptible:153   uninterruptible:0    total:154
cpu  7: runnable:1    interruptible:162   uninterruptible:0    total:163
cpu  8: runnable:0    interruptible:186   uninterruptible:0    total:186
cpu  9: runnable:1    interruptible:136   uninterruptible:0    total:137
cpu 10: runnable:2    interruptible:129   uninterruptible:1    total:132
cpu 11: runnable:1    interruptible:162   uninterruptible:0    total:163
cpu 12: runnable:1    interruptible:159   uninterruptible:0    total:160
cpu 13: runnable:2    interruptible:144   uninterruptible:0    total:146
cpu 14: runnable:2    interruptible:161   uninterruptible:0    total:163
cpu 15: runnable:3    interruptible:158   uninterruptible:0    total:161
cpu 16: runnable:2    interruptible:182   uninterruptible:0    total:184
cpu 17: runnable:1    interruptible:157   uninterruptible:0    total:158
cpu 18: runnable:1    interruptible:196   uninterruptible:1    total:198
cpu 19: runnable:1    interruptible:194   uninterruptible:0    total:195
cpu 20: runnable:1    interruptible:155   uninterruptible:0    total:156
cpu 21: runnable:0    interruptible:147   uninterruptible:0    total:147
cpu 22: runnable:0    interruptible:200   uninterruptible:0    total:200
cpu 23: runnable:3    interruptible:178   uninterruptible:0    total:181
cpu 24: runnable:4    interruptible:174   uninterruptible:0    total:178
cpu 25: runnable:1    interruptible:237   uninterruptible:0    total:238
cpu 26: runnable:1    interruptible:167   uninterruptible:0    total:168
cpu 27: runnable:1    interruptible:170   uninterruptible:0    total:171
cpu 28: runnable:3    interruptible:155   uninterruptible:0    total:158
cpu 29: runnable:1    interruptible:166   uninterruptible:0    total:167
cpu 30: runnable:1    interruptible:154   uninterruptible:0    total:155
cpu 31: runnable:1    interruptible:141   uninterruptible:0    total:142
cpu 32: runnable:2    interruptible:188   uninterruptible:0    total:190
cpu 33: runnable:1    interruptible:158   uninterruptible:0    total:159
cpu 34: runnable:1    interruptible:157   uninterruptible:0    total:158
cpu 35: runnable:1    interruptible:119   uninterruptible:0    total:120
cpu 36: runnable:0    interruptible:152   uninterruptible:0    total:152
cpu 37: runnable:1    interruptible:144   uninterruptible:0    total:145
cpu 38: runnable:1    interruptible:145   uninterruptible:1    total:147
cpu 39: runnable:1    interruptible:162   uninterruptible:0    total:163
 total: runnable:53   interruptible:6553   uninterruptible:3    total:6609
```
