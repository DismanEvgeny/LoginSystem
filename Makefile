EXEC = LoginSystem

default: 
	g++ -std=c++20 -o $(EXEC) Configuration.cpp crypt.cpp encrypt.cpp decrypt.cpp io.cpp login.cpp maint.cpp LoginSystem.cpp 
	
clean:
	$(RM) $(EXEC)