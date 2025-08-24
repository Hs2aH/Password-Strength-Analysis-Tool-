
if [ "$EUID" -ne 0 ]; then
    echo "Please run as root"
    exit 1
fi

if [$1 -eq ""] ; then
    echo "please enter the number of the hashes per second"
    echo "usage : $0 <hashes per second>"
    exit 1
fi


# Function to generate a random password of a given length
generate_password() {
    local length=$1
    tr -dc 'A-Za-z0-9' </dev/urandom | head -c "$length"
}

# Generate users and set random passwords
for i in {1..10}; do
    username="user$i"

    password=$(generate_password $i) # Generate a random password of length i

              # Create the user without home directory (-M) and set their password
              useradd -M "$username" || { echo "Failed to create user $username"; continue; }

                  # Set the password for the user
                  echo "$username:$password" | chpasswd
                  ./a.out $i $1

                  echo "Created $username with password: $password"
              done


              echo "User creation completed."
