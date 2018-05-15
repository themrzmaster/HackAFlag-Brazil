import idautils

x = 0
flag = ''
for function_ea in idautils.Functions():
    for ins in idautils.FuncItems(function_ea):
        if idaapi.isCode(idaapi.getFlags(ins)):
            cmd = idc.GetDisasm(ins)
            inst = cmd.split(' ')
            if 'call' in inst[0] and 'fgets' in inst[4]:
            	x = 1 
            if 'cmp' in inst[0] and x == 1:
            	mnem = inst[6]
            	if 'h' in mnem:
	            	mnem = mnem.replace('h', '')
	            	flag += mnem.decode("hex")

print flag


