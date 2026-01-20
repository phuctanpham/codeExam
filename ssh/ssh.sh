#!/bin/bash

# Ask for the passphrase
read -s -p "Enter passphrase: " passphrase
echo

# Create .ssh directory if it doesn't exist and set permissions
mkdir -p ~/.ssh
chmod 700 ~/.ssh

# Decrypt the deploy key into the .ssh directory
gpg --batch --yes --passphrase "$passphrase" -d -o ~/.ssh/deployKey deployKey.gpg

# Check if decryption was successful
if [ $? -ne 0 ]; then
    echo "Decryption failed. Please check your passphrase."
    rm -f ~/.ssh/deployKey # Clean up partially decrypted file
    exit 1
fi

# Set correct permissions for the private key
chmod 600 ~/.ssh/deployKey

# Add a config entry for GitHub if it doesn't exist
if ! grep -q "Host github.com" ~/.ssh/config 2>/dev/null; then
  echo "Adding GitHub config to ~/.ssh/config"
  cat << EOF >> ~/.ssh/config
Host github.com
  HostName github.com
  IdentityFile ~/.ssh/deployKey
  User git
EOF
  chmod 600 ~/.ssh/config
else
  echo "GitHub config already exists in ~/.ssh/config. Skipping."
fi

# Add GitHub's public key to known_hosts if it's not already there
if ! ssh-keygen -F github.com >/dev/null; then
    echo "Adding GitHub's public key to ~/.ssh/known_hosts"
    ssh-keyscan github.com >> ~/.ssh/known_hosts
else
    echo "GitHub's public key already in ~/.ssh/known_hosts. Skipping."
fi

# Set the remote URL to the correct SSH address
echo
echo "Setting git remote URL to SSH format..."
git remote set-url origin git@github.com:phuctanpham/codeExam.git

echo
echo "----------------------------------------------------------------"
echo "SSH configuration updated for GitHub."
echo "Your ~/.ssh/config is now set up to use your deploy key for github.com."
echo "Your git remote has been set to git@github.com:phuctanpham/codeExam.git"
echo "You can now push to your repository using the deploy key."
echo "----------------------------------------------------------------"
