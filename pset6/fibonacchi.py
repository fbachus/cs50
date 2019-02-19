fibotarget = int(input("What fibonacchi number should be calculated? :")) + 1

fibores=[]

def fibocalc(fibonr):
    if fibonr > 1:
        if len(fibores) > fibonr:
            fibonacchi = fibores[fibonr]
        else:
            fibonacchi = fibores[fibonr-1] + fibores[fibonr-2]
    else:
        fibonacchi = fibonr
    fibores.append(fibonacchi)
    return fibonacchi

for i in range(fibotarget):
    fibocalc(i)

print(fibores[-1::])