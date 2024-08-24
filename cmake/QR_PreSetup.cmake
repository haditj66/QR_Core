#this will find all packages that are for INTERFACES type packages ONLY
  macro(QR_presetup_of_project_files)
      set(options)
      set(oneValueArgs PROJECT_DIR)
      set(multiValueArgs  )
      cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

	
	#I need to create a bash file that will source all the packages this package depends on.
	#by default it will always source the interface package.
	
	#step 0. for this to work, timply have it that all QR projects send their project name (and 
	#any other needed presetup variables to a presetupvariables.cmake file) . this will happen in
	#qr_autos
	
	#step 1. I need a way to specify what all the depending packages are. I think having a .cmake
	#file that the user can fill in for a set(DEPENDING_PACKAGES ) and set(DEPENDING_INTERFACES )
	
	#step 2. this cmake file will read from that .cmake file and get list of  all packages
	
	#step 3. go through and get a list of all sub directories of the directories located in the 
	#QR_Core base directories ${QR_CORE_DIR}..  (also later we'll be able to specify other 
	#directories our packages can be located)
	
	#step 4. go through each subdirectory ${QR_CORE_DIR}/${theDIR}/cmake/presetupvariables.cmake
	# (if it exists) and check if the variable MY_PACKAGE_NAME equals the package. if so, save that 		# directory in a list variable and continue from the beggining of directories list. do this 	#until all depending pacakges are found. If one package was never found, throw a fatal error.
	
	#step 6. generate a bash file that has all the depending packages sourced within the bash. This
	# will most likely be a multiparameter template not needing cgen.
	
	#done.


      QR_Generate_File(
              WORKINGDIRECTORYOFINPUTFILE ${QR_CORE_DIR}
              WORKINGDIRECTORYOFOUTPUTFILE ${_arg_PROJECT_DIR}
              INPUT_FILE_NAME ourcolconbash
              OUTPUT_FILE_NAME ourcolcon
              OUTPUT_FILE_EXTENSION bash
      )

      QR_Generate_File(
              WORKINGDIRECTORYOFINPUTFILE ${QR_CORE_DIR}
              WORKINGDIRECTORYOFOUTPUTFILE ${_arg_PROJECT_DIR}
              INPUT_FILE_NAME ourcolconbat
              OUTPUT_FILE_NAME ourcolcon
              OUTPUT_FILE_EXTENSION bat
      )

      QR_Generate_File(
              WORKINGDIRECTORYOFINPUTFILE ${QR_CORE_DIR}
              WORKINGDIRECTORYOFOUTPUTFILE ${_arg_PROJECT_DIR}
              INPUT_FILE_NAME oursourcebash
              OUTPUT_FILE_NAME oursource
              OUTPUT_FILE_EXTENSION bash
      )

      QR_Generate_File(
              WORKINGDIRECTORYOFINPUTFILE ${QR_CORE_DIR}
              WORKINGDIRECTORYOFOUTPUTFILE ${_arg_PROJECT_DIR}
              INPUT_FILE_NAME oursourcebat
              OUTPUT_FILE_NAME oursource
              OUTPUT_FILE_EXTENSION bat
      )

  endmacro()
