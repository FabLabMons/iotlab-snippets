[{"id":"5542e30d.b86a0c","type":"function","z":"ed91000d.e405a","name":"convert int to buffer","func":"const buf = Buffer.alloc(2);\nbuf.writeInt16BE(msg.payload);\nmsg.payload = buf;\nreturn msg;","outputs":1,"noerr":0,"x":410,"y":180,"wires":[["282f248d.ecb1fc"]]}]
