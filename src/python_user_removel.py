
import os


user="user"

for i in range(1,11):
    user_del = user+str(i)
    os.system(f'userdel {user_del} -r')
