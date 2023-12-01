all:
	@echo "Choose your build:\n- raspi2"
.PHONY: all
.PHONY: sweeper

%:
	$(MAKE) -C sweeper
	$(MAKE) -C $@

.PHONY: clean
clean:
	rm -rf build objs
