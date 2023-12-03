TARGETS=$(shell ls arch)
all:
	@echo "Choose your build:"
	@$(foreach target,$(TARGETS),echo "- $(target)";)
.PHONY: all
.PHONY: sweeper

%:
	$(MAKE) -C arch/$@

.PHONY: clean
clean:
	rm -rf build objs
