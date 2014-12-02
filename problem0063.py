'''
I actually solved this program quite simply using on paper. I realized that
every number had an upper limit where the length of the power no longer
matched the power itself. I also realized that that no base 10 or greater
could satisfy this quality, and so the space in which there were possible
answers was shortened greatly. So I simply counted all the numbers that met
this requirement. In order to verify my answer I just threw together a quick
python script since I knew it could handle very large numbers quite easily.
'''

def num_len(x):
    l = 0
    while x > 0:
        x /= 10
        l+=1
    return l

c = 0
for i in range(1, 50):
    for j in range(1, 50):
        if j == num_len(i ** j):
            print i, j
            c+=1
print c