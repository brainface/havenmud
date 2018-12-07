Vagrant.configure("2") do |config|
  config.vm.define "haven" do |haven|
   #haven.vm.box="centos/6"
   haven.vm.box="geerlingguy/centos6"
   haven.vm.network :forwarded_port, host: 4000, guest: 4000
   haven.vm.provider "Virtualbox" do |v|
    v.customize ['modifyvm', :id, '--nictype1', 'virtio']
    v.memory = 512
   end

  # only on initial 'up': run our ansible deploys
   haven.vm.provision "ansible" do |ansible|
     ansible.playbook = "ansible/testbox_setup.yaml"
   end

 if File.exist?(".vagrant/machines/haven/virtualbox/action_provision")
   haven.vm.synced_folder ".", "/home/haven/haven", create: true, group: "haven", owner: "haven"
 end
end
end
