EXEC = LoginSystem

all: 
	g++ -std=c++2a -o $(EXEC) Configuration.cpp crypt.cpp encrypt.cpp decrypt.cpp io.cpp login.cpp maint.cpp LoginSystem.cpp 
	
clean:
	$(RM) $(EXEC)