blocksSize = int(input())
blocks = dict()
for i in range(blocksSize):
  blocks[i] = [str(i)]

command = input()
while(command!="quit"):
  commandBreak = command.split()
  
  key_a = [key for key, val in blocks.items() if commandBreak[1] in val][0]
  key_b = [key for key, val in blocks.items() if commandBreak[3] in val][0]

  if(key_a!=key_b):
    if commandBreak[0] == "move":
      if (blocks[key_a].index(commandBreak[1])==0 and len(blocks[key_a])<=1):
        blocks[key_a] = []
        temp_a = []
      else:
        temp_a = blocks[key_a][blocks[key_a].index(commandBreak[1])+1:]
        blocks[key_a] = blocks[key_a][:blocks[key_a].index(commandBreak[1])]
      
      if commandBreak[2] == "over":
        blocks[key_b].append(commandBreak[1])
      else:
        temp_b = blocks[key_b][blocks[key_b].index(commandBreak[3])+1:]
        blocks[key_b] = blocks[key_b][:blocks[key_b].index(commandBreak[3])+1]        
        blocks[key_b].append(commandBreak[1])
        for item in temp_b:
          blocks[int(item)].insert(0, item)
      for item in temp_a:
        blocks[int(item)].insert(0,item)
      
    else:
      temp = blocks[key_a][blocks[key_a].index(commandBreak[1]):]
      blocks[key_a] = blocks[key_a][:blocks[key_a].index(commandBreak[1])]
      if commandBreak[2] == "onto":
        temp_b = blocks[key_b][blocks[key_b].index(commandBreak[3])+1:]
        blocks[key_b] = blocks[key_b][:blocks[key_b].index(commandBreak[3])+1]
        blocks[key_b].extend(temp)
      else:
        temp_b = []
        blocks[key_b].extend(temp)
      for item in temp_b:
        blocks[int(item)].insert(0, item)
  command = input()
  

for i in range(blocksSize):
  if len(blocks[i])!=0:
    print(f'{i}: {" ".join(blocks[i])}')
  else:
    print(f'{i}:')