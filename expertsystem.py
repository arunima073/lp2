def rule1(symptons):
    if 'bricks' in symptons and 'wood' in symptons:
        return 'Building purpose'
    return None

def rule2(symptons):
    if 'pumpkin' in symptons and 'tomatoes' in symptons:
        return 'Vegetable vendor'
    return None

def rule3(symptons):
    if  'crocin' in symptons and 'cough syrup' in symptons:
        return 'Medical Emergency'
    return None

def diagnosis(symptons):
    ruless=[rule1,rule2,rule3]
    results=[]
    for x in ruless:
        result=x(symptons)
        if result:
            results.append(result)
    if(len(results)==0):
        return 'Sorry nothing matches'
    elif(len(results)==1):
        return results[0]
    else:
        return results
    
symptons = []
n = int(input("Enter number of elements : "))
for i in range(0, n):
    ele = input()
    symptons.append(ele)

result=diagnosis(symptons)
print(result)
    