def push(stack,top_param,val):
	global top
	#print("-",stack,top_param,val)
	if overflow(stack,top)==False:
		top+=1
		stack[top]=val
		res = "\nPush operation Done."
		return res
	else:
		res = "\n=>Stack is over flow."
		return res

def pop(stack,top_param):
	global top
	if underflow(stack,top)==False:
		poped_element=stack[top]
		#stack.pop(top)
		stack[top]=None
		top-=1
		res = "\nPop operation Done & poped element is: {}".format(poped_element)
		return res
	else:
		res = "\n=>Stack is under flow."
		return res

def isempty(stack,top_param):
	global top
	if top==-1:
		return True
	else:
		return False

def overflow(stack,top_param):
	global top,  len_of_Stack
	if top==(len_of_Stack-1):
		return True
	else:
		return False

def underflow(stack,top_param):
	global top
	if top==-1:
		return True
	else:
		return False

# Main driver code

print("-"*10,">"," Stack using Python ","<","-"*10)
print('''
	1. push:			push <element>
	2. pop:				pop
	3. isempty:			isempty
	4. check current stack:		stack
	5. Top element:			top
	6. Exit				exit
	''')
print("-"*50)
len_of_Stack = int(input("\nEnter the size of Stack: "))

stack=[None]*len_of_Stack
top=-1

while(True):

	choice=input("\nEnter operation to be perform as per described: ").split(" ")

	if choice[0]=='push':
		print(push(stack,top,choice[1]))
		
	elif choice[0]=='pop':
		print(pop(stack,top))
	
	elif choice[0]=='isempty':
		print("\nisempty result: ",isempty(stack,top))
	
	elif choice[0]=='stack':
		print("\nStack: ", stack)

	elif choice[0]=='top':
		print("\nTop: ", stack[top])
	
	elif choice[0]=='exit':
		break

	else:
		print("\n=>Invalid choice of Stack operation!")


"""
# PUSH OPs
print(push(stack,top,1))
print(push(stack,top,2))
print(push(stack,top,3))
print(push(stack,top,3))
print(push(stack,top,5))
print(push(stack,top,5))

print("\nisempty result: ",isempty(stack,top))

print("\nStack: ", stack)
print("Top: ", top)

# POP OPs
print(pop(stack,top))
print(pop(stack,top))
print(pop(stack,top))

print("\nStack: ", stack)
print("Top: ", top)

print("\nisempty result: ",isempty(stack,top))

print(pop(stack,top))
print(pop(stack,top))

print("\nStack: ", stack)
print("Top: ", top)

print("\nisempty result: ",isempty(stack,top))

print(pop(stack,top))
"""