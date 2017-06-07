desc "clean up generated files"
task :clean do
  sh "rm -f main dynamic-main static-main *.so"
  sh "find . -type f -iname '*.o' -exec rm {} +"
end

desc "generate all the object files"
task :object

desc "generate all the shared object files"
task :shared

desc "dynamic shared object"
file "libdyn.so"

# Dependencies involving .c files
Dir["lib/*"].each do |c_file|
  object_file = "objects/#{File.basename(c_file)[0...-1]}o"
  shared_file = "shared/#{File.basename(c_file)[0...-1]}o"
  desc "generate statically linkable .o file for #{c_file}"
  file object_file => c_file do
    sh "cd objects && gcc -c ../#{c_file}"
  end
  desc "generate dynamically linkable .o file for #{c_file}"
  file shared_file => c_file do
    sh "cd shared && gcc -c -fpic ../#{c_file}"
  end
  file "static-main" => object_file
  file "dynamic-main" => shared_file
  task :objects => object_file
  task :shared => shared_file
  file "libdyn.so" => shared_file
end

file "libdyn.so" do
  sh "gcc -shared -o libdyn.so shared/*"
end

desc "compile main executable statically"
file "static-main" do
  sh "gcc main.c -Wall -o static-main objects/*"
end

desc "compile main executable dynamically"
file "dynamic-main" => "libdyn.so" do
  sh "gcc main.c -Wall -o dynamic-main -ldyn -L."
end
